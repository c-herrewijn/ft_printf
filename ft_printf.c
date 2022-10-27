/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 20:30:20 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/10/27 17:52:39 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_va_arg(const char format_char, int *print_len, va_list ap)
{
	char					c;
	long long int			nr;
	unsigned long long int	uns_nr;
	char					*str;

	if (format_char == 'c')
	{
		c = va_arg(ap, int);
		*print_len += write(1, &c, 1);
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
			*print_len += write(1, "(null)", 6);
	}
	if (format_char == 'p')
	{
		uns_nr = va_arg(ap, unsigned long long int);
		*print_len += write(1, "0x", 2);
		printf_putpointer(uns_nr, print_len);
	}
	if (format_char == 'd' || format_char == 'i')
	{
		nr = va_arg(ap, int);
		printf_putnbr(nr, print_len);
	}
	if (format_char == 'u')
	{
		uns_nr = va_arg(ap, unsigned int);
		printf_putunsnbr(uns_nr, print_len);
	}
	if (format_char == 'x')
	{
		uns_nr = va_arg(ap, unsigned int);
		printf_putunsignedhex(uns_nr, print_len, 'l');
	}
	if (format_char == 'X')
	{
		uns_nr = va_arg(ap, unsigned int);
		printf_putunsignedhex(uns_nr, print_len, 'u');
	}
	if (format_char == '%')
	{
		*print_len += write(1, "%", 1);
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
			print_len += write(1, format, 1);
		}
		format++;
	}
	va_end(ap);
	return (print_len);
}
