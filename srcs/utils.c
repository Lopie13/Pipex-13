#include "../pipex.h"

	//does the specified commands somehow...
	//using split maybe? or idk
void	commands(char *argv, char **envp)
{
	char	*path;
	char	**cmd;
	int	melon;

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
	if (!(execve(path, cmd, envp)))
		error();
}

char	*find_path(char *cmd, char **envp)
{
	char	**allpaths;
	char	*path;
	char	*partpath;
	int		i;

	i = 0;
	/* while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++; */
	while (envp[i] && strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	allpaths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (allpaths[i])
	{
		partpath = ft_strjoin(allpaths[i], "/");//this adds a "/" to the path i think??
		path = ft_strjoin(partpath, cmd);       // then here it adds the command infront of the path
		free(partpath);                         // allpaths[i] - PATH | partpath - PATH/ path - PATH/cmd
		if (access(path, F_OK) == 0)
			return (path); //free array pls thnk u
		free(path);
		i++;
	}
	i = -1;
	while (allpaths[++i])
		free(allpaths[i]);
	free(allpaths);
	return (0);
}

void	error()
{
	perror("\033[31mError\033[0m");
	exit(EXIT_FAILURE);
}