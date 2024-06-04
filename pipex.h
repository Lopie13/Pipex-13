/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:45:03 by mmata-al          #+#    #+#             */
/*   Updated: 2024/06/04 11:14:47 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	clean_pipes(int *fd);
void	errormain(void);

#endif