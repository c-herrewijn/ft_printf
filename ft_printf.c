/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 20:30:20 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/10/26 11:51:38 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_va_arg(const char format_char, int *print_len, va_list ap)
{
	char	c;
	int		nr;
	char	*str;

	if (format_char == '%')
	{
		write(1, "%", 1);
		*print_len += 1;
	}
	if (format_char == 'c')
	{
		c = va_arg(ap, int);
		write(1, &c, 1);
		*print_len += 1;
	}
	if (format_char == 'd')
	{
		nr = va_arg(ap, int);
		str = ft_itoa(nr);
		ft_putstr_fd(str, 1);
		*print_len += ft_strlen(str);
		free (str);
	}
	if (format_char == 's')
	{
		str = va_arg(ap, char *);
		if (str)
		{
			ft_putstr_fd(str, 1);
			*print_len += ft_strlen(str);
		}
		else
		{
			write(1, "(null)", 6);
			*print_len += 6;
		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*format_chars;
	int		print_len;

	va_start(ap, format);
	format_chars = "cspdiuxX";
	print_len = 0;
	if (get_nr_formats(format, format_chars) < 0)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print_va_arg(*format, &print_len, ap);
		}
		else
		{
			write(1, format, 1);
			print_len++;
		}
		format++;
	}
	va_end(ap);
	return (print_len);
}
