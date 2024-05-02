/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:34:43 by mmata-al          #+#    #+#             */
/*   Updated: 2023/11/10 17:08:32 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	getlen(long n, char *base)
{
	int	numl;
	int	basel;

	numl = 0;
	basel = 0;
	while (base[basel])
		basel++;
	while (n != 0)
	{
		n /= basel;
		numl++;
	}
	return (numl);
}

void	ft_putcharr(int c)
{
	write(1, &c, 1);
}

int	ft_check_base(char *shira)
{
	int	melon;
	int	soda;

	if (!shira)
		return (1);
	while (*shira)
	{
		if (*shira == '+' || *shira == '-' || *shira == ' '
			|| (*shira >= 9 && *shira <= 13))
			return (1);
		shira++;
	}
	melon = 0;
	while (shira[melon])
	{
		soda = melon;
		while (shira[soda])
		{
			if (shira[melon] == shira[soda + 1])
				return (1);
			soda++;
		}
		melon++;
	}
	return (0);
}

int	ft_putnbr_base(long nbr, char *base)
{
	long	size;
	long	number;
	int		len;

	len = getlen(nbr, base);
	number = nbr;
	if (ft_check_base(base) == 1)
		return (0);
	size = 0;
	while (base[size])
		size++;
	if (number < 0)
	{
		ft_putcharr('-');
		ft_putnbr_base(nbr * -1, base);
	}
	else 
	{
		if (number >= size)
			ft_putnbr_base((number / size), base);
		ft_putcharr(base[(number % size)]);
	}
	return (len + (nbr <= 0));
}
/* 
#include <stdio.h>

int main(void)
{
	char base[] = "ShiraMelonSoda";
	long aloo = -247483647;
	//int test = ('+' - 48);
	//char a = test;

	ft_putnbr_base(aloo, base);
	printf("\n");
	//write(1, &a, 1);
	return 0;
} */
