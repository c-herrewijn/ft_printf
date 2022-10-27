/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/14 16:32:47 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/10/27 17:51:03 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_putnbr(int nbr, int *print_len)
{
	char	c;

	if (nbr == -2147483648)
		*print_len += write(1, "-2147483648", 11);
	else
	{
		if (nbr < 0)
		{
			nbr = nbr * (-1);
			*print_len += write(1, "-", 1);
		}
		if (nbr < 10)
		{
			c = nbr + '0';
			*print_len += write(1, &c, 1);
		}
		else
		{
			printf_putnbr(nbr / 10, print_len);
			printf_putnbr(nbr % 10, print_len);
		}
	}
}

void	printf_putunsnbr(unsigned int nbr, int *print_len)
{
	char	c;

	if (nbr < 10)
	{		
		c = nbr + '0';
		*print_len += write(1, &c, 1);
	}
	else
	{
		printf_putunsnbr(nbr / 10, print_len);
		printf_putunsnbr(nbr % 10, print_len);
	}
}

void	printf_putunsignedhex(unsigned int nbr, int *print_len, char var_case)
{
	char	*base;

	base = NULL;
	if (var_case == 'l')
		base = "0123456789abcdef";
	else if (var_case == 'u')
		base = "0123456789ABCDEF";
	if (base)
	{
		if (nbr < 16)
			*print_len += write(1, &base[nbr], 1);
		else
		{
			printf_putunsignedhex(nbr / 16, print_len, var_case);
			*print_len += write(1, &base[nbr % 16], 1);
		}
	}
}

void	printf_putpointer(unsigned long long nbr, int *print_len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
		*print_len += write(1, &base[nbr], 1);
	else
	{
		printf_putpointer(nbr / 16, print_len);
		*print_len += write(1, &base[nbr % 16], 1);
	}
}
