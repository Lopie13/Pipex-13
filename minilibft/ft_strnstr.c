/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:39:24 by mmata-al          #+#    #+#             */
/*   Updated: 2023/10/10 15:23:55 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	int	melon;
	int	soda;

	melon = 0;
	if (ft_strlen((char *)to_find) == 0)
		return ((char *)str);
	while (str[melon] && (melon < (int)n || (int)n == -1))
	{
		soda = 0;
		while (str[melon + soda] == to_find[soda] 
			&& str[melon + soda]
			&& ((melon + soda) < (int)n || (int)n == -1))
			soda++;
		if (to_find[soda] == '\0')
			return ((char *)(str + melon));
		melon++;
	}
	return (NULL);
}
/* 
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t n);

int main(void)
{
    const char *haystack = "MZIRIBMZIRIBMZE123";
    const char *needle1 = "MZIRIBMZE";
    const char *needle2 = "Melon";
    const char *needle3 = "soda";

    char *result1 = ft_strnstr(haystack, needle1, 10);
    char *result2 = ft_strnstr(haystack, needle2, 30);
    char *result3 = ft_strnstr(haystack, needle3, 30);

    printf("Result 1: %s\n", result1 ? result1 : "Not found");
    printf("Result 2: %s\n", result2 ? result2 : "Not found");
    printf("Result 3: %s\n", result3 ? result3 : "Not found");

    return 0;
} */
