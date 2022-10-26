/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 20:30:20 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/10/26 09:55:43 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	print_va_arg(const char *format, int *return_val, va_list ap)
{
	char c;
	int nr;
	char *str;

	if (*format == 'c')
	{
		c = va_arg(ap, int);
		write(1, &c, 1);
		*return_val += 1;
	}
	if (*format == 'd')
	{
		nr = va_arg(ap, int);
		str = ft_itoa(nr);
		ft_putstr_fd(str, 1);
		*return_val += ft_strlen(str);
		free (str);
	}
	if (*format == 's')
	{
		str = va_arg(ap, char*);
		ft_putstr_fd(str, 1);
		*return_val += ft_strlen(str);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*format_chars;
	int		return_val;

	va_start(ap, format);
	format_chars = "cspdiuxX";
	return_val = 0;
	if (get_nr_formats(format, format_chars) < 0)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print_va_arg(format, &return_val, ap);
		}
		else
		{
			write(1, format, 1);
			return_val++;
		}
		format++;
	}
	va_end(ap);
	return (return_val);
}
