/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:36:18 by mmata-al          #+#    #+#             */
/*   Updated: 2023/11/09 18:11:21 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	writenil(void)
{
	write(1, &"(nil)", 5);
	return (5);
}

int	ft_put_pointer_addr(void *p)
{
	unsigned long	nb;
	char			str[16];
	char			*base;
	int				len;
	int				i;

	base = "0123456789abcdef";
	nb = (unsigned long)p;
	if (nb == 0)
		return (writenil());
	write(1, "0x", 2);
	i = 0;
	while (nb != 0) 
	{
		str[i] = base[nb % 16];
		nb /= 16;
		i++;
	}
	len = i;
	while (i >= 1)
	{
		write(1, &str[i - 1], 1);
		i--;
	}
	return (len + 2);
}
