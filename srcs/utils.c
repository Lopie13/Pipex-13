/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:45:27 by mmata-al          #+#    #+#             */
/*   Updated: 2024/06/04 11:17:10 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

	//does the specified commands somehow...
	//using split maybe? or idk

char	*find_path(char *cmd, char **envp)
{
	char	**allpaths;
	char	*path;
	char	*partpath;
	int		i;

	i = 0;
	while (envp[i] && strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	allpaths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (allpaths[i])
	{
		partpath = ft_strjoin(allpaths[i], "/");
		path = ft_strjoin(partpath, cmd);
		free(partpath);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (allpaths[++i])
		free(allpaths[i]);
	free(allpaths);
	return (0);
}

void	commands(char *argv, char **envp)
{
	char	*path;
	char	**cmd;
	int		melon;

	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		melon = 0;
		while (cmd[melon])
		{
			free(cmd[melon]);
			melon++;
		}
		free(cmd);
		error();
	}
	execve(path, cmd, envp);
	error();
}

void	clean_pipes(int fd[2])
{
	close(fd[1]);
	close(fd[0]);
}

void	error(void)
{
	perror("\033[31mError\033[0m");
	exit(EXIT_FAILURE);
}

void	errormain(void)
{
	ft_printf("Error: Bad arguments\n");
	ft_printf("Should be: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	exit(EXIT_FAILURE);
}
