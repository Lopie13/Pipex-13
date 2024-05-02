#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "minilibft/ft_printf.h"

void	commands(char *argv, char **envp);
void	error(void);
char	*find_path(char *cmd, char **envp);

#endif