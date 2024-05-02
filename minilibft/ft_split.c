/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:28:52 by mmata-al          #+#    #+#             */
/*   Updated: 2023/10/17 10:26:06 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	i = 0;
	result = ft_calloc(ft_words(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	j = 0;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		k = 0;
		while (s[j + k] != c && s[j + k])
			k++;
		if (k > 0)
		{
			result[i] = ft_substr(s, j, k);
			i++;
		}
		j += k;
	}
	return (result);
}
/* 
#include <stdio.h>

int main(void)
{
    char const *str = "Shira Melon Soda";
    char c = ' ';

    char **result = ft_split(str, c);

    // Prints the split strings
    for (int i = 0; result[i] != NULL; i++)
    {
        printf("%s\n", result[i]);
    }

    // Free the allocated memory
    for (int i = 0; result[i] != NULL; i++)
    {
        free(result[i]);
    }
    free(result);
    return 0;
} */
