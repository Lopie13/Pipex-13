#include "../pipex.h"

void	child_two(char **argv, char **envp, int *fd)
{
	int	outfile;

	printf("test");
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	clean_pipes(fd);
	commands(argv[3], envp);
}

void	child_one(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		error();
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		error();
	if (dup2(infile, STDIN_FILENO) < 0)
	close(fd[0]);
	clean_pipes(fd);
	commands(argv[2], envp);
}

int	main(int argc, char *argv[], char **envp)
{
	int fd[2];
	int pid1;
	int pid2;
	int status;

	status = 0;
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			return 1;
		pid1 = fork();
		if (pid1 < 0)
			return 2;
		if (pid1 == 0)
			child_one(argv, envp, fd);
		pid2 = fork();
		if (pid2 < 0)
			return 2;
		if (pid2 == 0)
			child_two(argv, envp, fd);
		else
		{
			clean_pipes(fd);
			waitpid(pid1, NULL, 0);
			waitpid(pid2, &status, 0);
		}
	}
	else
	{
		ft_printf("Error: Bad arguments\n");
		ft_printf("Should be: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	}
	exit(EXIT_SUCCESS);
	return (0);
}