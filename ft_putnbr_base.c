/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/14 16:32:47 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/10/27 17:21:04 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_base(char *base)
{
	int		i;
	char	*p_j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] == 127)
			return (-1);
		p_j = (&base[i] + 1);
		while (*p_j)
		{
			if (base[i] == *p_j)
				return (-1);
			p_j++;
		}
		i++;
	}
	if (i < 2)
		return (-1);
	else
		return (i);
}

size_t	ft_putnbr_base(long long int nbr, char *base)
{
	int				last_digit;
	int				int_base;
	long long int	abs_nbr;
	size_t			write_len;

	write_len = 0;
	int_base = len_base(base);
	if (int_base != -1)
	{
		if (nbr < 0)
		{
			write_len += write(1, "-", 1);
			abs_nbr = (nbr * -1);
		}
		else
			abs_nbr = nbr;
		if (abs_nbr >= int_base)
			write_len += ft_putnbr_base(abs_nbr / int_base, base);
		last_digit = abs_nbr % int_base;
		write_len += write(1, &base[last_digit], 1);
	}
	return (write_len);
}

void	ft_putpointer(unsigned long long nbr, int *print_len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
		*print_len += write(1, &base[nbr], 1);
	else
	{
		ft_putpointer(nbr / 16, print_len);
		*print_len += write(1, &base[nbr % 16], 1);
	}
}

void	ft_putunsignedhex(unsigned int nbr, int *print_len, char var_case)
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
			ft_putunsignedhex(nbr / 16, print_len, var_case);
			*print_len += write(1, &base[nbr % 16], 1);
		}
	}
}

void	ft_putunsnr(unsigned int nbr, int *print_len)
{
	char	c;

	if (nbr < 10)
	{		
		c = nbr + '0';
		*print_len += write(1, &c, 1);
	}
	else
	{
		ft_putunsnr(nbr / 10, print_len);
		ft_putunsnr(nbr % 10, print_len);
	}
}
