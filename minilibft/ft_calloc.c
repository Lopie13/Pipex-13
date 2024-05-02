/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:35:53 by mmata-al          #+#    #+#             */
/*   Updated: 2023/10/13 16:46:05 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*thing;

	thing = malloc(nmemb * size);
	if (thing == NULL)
	{
		return (thing);
	}
	ft_bzero(thing, size * nmemb);
	return (thing);
}
/* 
//shira
#include <stdio.h>
int main(void)
{
    size_t num_elements = 5;
    size_t element_size = sizeof(int);
    
    // Allocate memory using your ft_calloc
    int *arr = ft_calloc(num_elements, element_size);

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Check if the allocated memory is initialized to zero
    for (size_t i = 0; i < num_elements; i++)
    {
        if (arr[i] != 0)
        {
            printf("Memory not initialized to zero at index %zu.\n", i);
            return 1;
        }
    }

    printf("Memory allocation and initialization successful.\n");

    // Don't forget to free the allocated memory
    free(arr);

    return 0;
} */