/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:33:52 by mmata-al          #+#    #+#             */
/*   Updated: 2023/11/06 17:08:18 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <fcntl.h>

// int main(void)
// {
// 	int fd;
// 	char c;

// 	fd = open("filename.txt", O_RDONLY);
// 	ft_putchar_fd(c, fd);
// }
//does this actually work? no idea, but probably not!