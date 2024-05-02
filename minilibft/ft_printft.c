/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:53:12 by mmata-al          #+#    #+#             */
/*   Updated: 2023/11/10 17:09:46 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

int	chekif(va_list argss)
{
	void	*temp;

	temp = va_arg(argss, char *);
	if (!temp)
		temp = "(null)";
	ft_putstr_fd((char *)temp, 1);
	return (ft_strlen(temp));
}

int	exist(char ph, char *opt)
{
	while (*opt)
	{
		if (ph == *opt)
			return (1);
		opt++;
	}
	return (0);
}

int	check(char *ph, va_list ar)
{
	char	*opts;

	opts = "cspdiuxX%";
	if (!exist(*(ph + 1), opts))
		return (0);
	ph++;
	if (*ph == 'c')
		ft_putchar_fd(va_arg(ar, int), 1);
	else if (*ph == 's')
		return (chekif(ar));
	else if (*ph == 'd' || *ph == 'i')
		return (ft_putnbr_base(va_arg(ar, int), "0123456789"));
	else if (*ph == 'p')
		return (ft_put_pointer_addr(va_arg(ar, void *)));
	else if (*ph == 'u')
		return (ft_putnbr_base(va_arg(ar, unsigned int), "0123456789"));
	else if (*ph == 'x')
		return (ft_putnbr_base(va_arg(ar, unsigned int), "0123456789abcdef"));
	else if (*ph == 'X')
		return (ft_putnbr_base(va_arg(ar, unsigned int), "0123456789ABCDEF"));
	else if (*ph == '%')
		ft_putchar_fd('%', 1);
	return (1);
}

int	ft_printf(const char *placeholder, ...)
{
	char	*ph;
	int		num_count;
	int		hold;
	va_list	args;

	hold = 0;
	num_count = 0;
	ph = (char *)placeholder;
	va_start(args, placeholder);
	while (ph[hold])
	{
		if (ph[hold] == '%')
		{
			num_count = num_count + check(&(ph[hold]), args);
			hold = hold + 2;
		}
		else
		{
			ft_putchar_fd(ph[hold], 1);
			hold++;
			num_count++;
		}
	}
	va_end(args);
	return (num_count);
}
/* 
int	main(void)
{
	int min = -2147483648;
	int max = 2147483647;
	int test;
	//ft_printf("ShiraMelonSoda %d", 13, 14);
	printf("\n\ncontrol:\n%d\n", 0);
	printf("%d\n", min);
	printf("%d\n", max);

	printf("\nreturns control:\n");
	test = printf("%d", 0);
	printf("%d\n", test);
	test = printf("%d", min);
	printf("%d\n", test);
	test = printf("%d", max);
	printf("%d\n", test);

	ft_printf("\nMYft:\n%d\n", 0);
	ft_printf("%d\n", min);
	ft_printf("%d\n", max);
	
	printf("\nmyreturn\n");
	test = ft_printf("%d", 0);
	printf("%d\n", test);
	test = ft_printf("%d", min);
	printf("%d\n", test);
	test = ft_printf("%d", max);
	printf("%d\n", test);

	return (0);
} */