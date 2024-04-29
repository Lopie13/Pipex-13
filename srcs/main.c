#include "../pipex.h"

void	parent_process(char **argv, char **envp, int *fd)
{
	//teaches the child how to eat or something idk im not a parent
}

void	child_process(char **argv, char **envp, int *fd)
{
	int		infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		error(/*function*/);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	command(argv[2], envp);
}

int	main(int argc, char *argv[], char **envp)
{
	int fd[2];
	int pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			return 1;
		pid1 = fork();
		if (pid1 < 0)
			return 2;
		if (pid1 == 0)
			child_process(argv, envp, fd);
		waitpid(pid1, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
	{
		printf("Error: Bad arguments\n");
		printf("Should be: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	}
	return (0);
}