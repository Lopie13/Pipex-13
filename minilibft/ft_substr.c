/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:08:49 by mmata-al          #+#    #+#             */
/*   Updated: 2023/10/13 17:39:01 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned long	strlen;

	strlen = (unsigned long)ft_strlen((char *)s);
	i = start;
	if (start >= strlen)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > strlen + 1)
		str = ft_calloc((strlen - start) + 1, sizeof(char));
	else
		str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] && i < start + len)
	{
		str[i - start] = s[i];
		i++;
	}
	str[i - start] = '\0';
	return (str);
}
/* 
#include <stdio.h>

int main(void)
{
	char strng[] = "ShiraMelonSoda";
	unsigned int srt = 5;
	size_t l = 5;
	char *dest;

	dest = ft_substr(strng, srt, l);
	printf("%s", dest);
	return (0);
} */