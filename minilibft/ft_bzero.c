/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:10:59 by mmata-al          #+#    #+#             */
/*   Updated: 2023/10/13 16:46:56 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *a, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)a;
	while (n > 0)
	{
		*(str++) = 0;
		n--;
	}
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    char str1[] = "Test string";

    // Using the custom bzero
    bzero(str1, sizeof(str1));

    printf("Custom bzero: \"%s\"\n", str1);

    char str2[] = "Test string";

    // Using the standard bzero from string.h
    memset(str2, 0, sizeof(str2));

    printf("Standard bzero: \"%s\"\n", str2);

    return 0;
}*/