/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 15:13:47 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/10/23 12:49:26 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
duplicates a string to new memory
copies not more than n chars, and not more chars than present in the string
one extra byte is allocated for the new string, so it is null terminated
if malloc fails, NULL is returned
*/
static char	*ft_strndup(const char *s1, size_t max_len)
{
	size_t		len;
	size_t		i;
	const char	*s_iter;
	char		*s2;

	if (!s1)
		return (NULL);
	i = 0;
	len = 0;
	s_iter = s1;
	while (*s_iter && len < max_len)
	{
		len++;
		s_iter++;
	}
	s2 = (char *)ft_calloc(len + 1, sizeof(char));
	if (s2 == NULL)
		return (s2);
	while (i < len)
	{
		*(s2 + i) = *(s1 + i);
		i++;
	}
	return (s2);
}

/*
copies a substring to new memory
starting at position 'start' not more than 'len' chars
copies not more chars than present in the string
one extra byte is allocated for the new string, so it is null terminated
note: 'start' is a zero-based index!
if malloc fails, NULL is returned
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strndup("", 0));
	i = 0;
	while (i < start)
	{
		s++;
		i++;
	}
	return (ft_strndup(s, len));
}
