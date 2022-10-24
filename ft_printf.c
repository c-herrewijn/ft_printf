/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 20:30:20 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/10/24 15:38:56 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	char	*format_chars;
	int		nr_formats;

	format_chars = "cspdiuxX";
	nr_formats = get_nr_formats(format, format_chars);
	if (nr_formats < 0)
		return (-1);
	return (42);
}
