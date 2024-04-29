#include "../pipex.h"

	//does the specified commands somehow...
	//using split maybe? or idk
void	command(char *argv, char **envp)
{
	char	*path;
	char	*cmd;
	int	melon;

	cmd = ft_split(argv);
	path = find_path(cmd[0], envp);
	if (!path)	
	{
		while (cmd[melon])
		{
			free(cmd[melon]);
			melon++;
		}
		free(cmd);
		error();
	}
}

char	*find_path(char *cmd, char **envp)
{
	//somehow finds the path to the commands we need?
}

void	error()
{
	//prints error and quits
}