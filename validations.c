/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validations.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:17:03 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/10/24 15:32:35 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
returns the number of formats, or -1 in case the format string is invalid
a '%' sign should be followed by a format char 
2 consequtive '%%' chars in the format string are printed '%'
*/
int	get_nr_formats(const char *format_str, char *format_chars)
{
	int	format_count;
	int	i;

	i = 0;
	format_count = 0;
	while (format_str[i])
	{
		if (format_str[i] == '%')
		{			
			if (format_str[i + 1] && ft_strchr(format_chars, format_str[i + 1]))
			{
				i++;
				format_count++;
			}
			else if (format_str[i + 1] == '%')
				i++;
			else
				return (-1);
		}
		i++;
	}
	return (format_count);
}
