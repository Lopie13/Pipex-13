#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
//# include <sys/wait.h>
# include <fcntl.h>

void	command(char *argv, char **envp);

#endif