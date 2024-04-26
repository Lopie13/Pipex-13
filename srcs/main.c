#include "../pipex.h"

int	main(int argc, char *argv[])
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
			child_process();
		waitpid(pid1, NULL, 0);
		parent_process();
	}
	else
	{
		printf("Error: Bad arguments\n");
		printf("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	}
	return (0);
}