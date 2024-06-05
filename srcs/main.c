/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:46:49 by mmata-al          #+#    #+#             */
/*   Updated: 2024/06/04 16:25:04 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		error();
	close(fd[0]);
	clean_pipes(fd);
	commands(argv[2], envp);
}

int	parent(int *pids, char **argv, char **envp)
{
	int	fd[2];

	if (pipe(fd) == -1)
		return (1);
	pids[1] = fork();
	if (pids[1] < 0)
		return (2);
	if (pids[1] == 0)
		child_one(argv, envp, fd);
	pids[2] = fork();
	if (pids[2] < 0)
		return (2);
	if (pids[2] == 0)
		child_two(argv, envp, fd);
	else
	{
		clean_pipes(fd);
		waitpid(pids[1], NULL, 0);
		waitpid(pids[2], &pids[0], 0);
	}
	return (0);
}

int	main(int argc, char *argv[], char **envp)
{
	int	pids[3];

	pids[0] = 0;
	if (!argv[2][0] || !argv[3][0])
		errormain();
	if (argc == 5)
		return (parent(pids, argv, envp));
	else
		errormain();
	exit(0);
}
//pids is an array containing pid 1 and 2 + pids[0] = 0