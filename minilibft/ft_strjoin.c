/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:09:58 by mmata-al          #+#    #+#             */
/*   Updated: 2023/10/13 17:03:15 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}
/* 
#include <stdio.h>

int main(void)
{
    char *strs[] = {"ShiraMelonSoda", "ShiraMelonSoda", "!!!"};
    char *sep = " shrkDinkDonk ";

    char *result = ft_strjoin(strs, sep);

    if (result)
    {
        printf("Concatenated String: %s\n", result);
        free(result); // yes this int main was made using chatgpt
    }		      // dont like it? didnt ask 
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
} */