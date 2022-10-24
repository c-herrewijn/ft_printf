/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 15:07:22 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/10/23 12:18:40 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates bytes based on object size and nr. of objects
Makes sure the allocated volume is empty
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	i;

	str = malloc(count * size);
	if (str == NULL)
		return (str);
	i = 0;
	while (i < (count * size))
	{
		*(unsigned char *)(str + i) = '\0';
		i++;
	}
	return (str);
}
