/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/14 16:32:47 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/10/27 11:05:35 by cherrewi      ########   odam.nl         */
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

size_t	ft_putnbr_base(int nbr, char *base)
{
	int			last_digit;
	int			int_base;
	long int	li_nbr;
	size_t		write_len;

	write_len = 0;
	int_base = len_base(base);
	if (int_base != -1)
	{
		if (nbr < 0)
		{
			write_len += write(1, "-", 1);
			li_nbr = ((long int)nbr * -1);
		}
		else
			li_nbr = (long int)nbr;
		if (li_nbr >= int_base)
			write_len += ft_putnbr_base(li_nbr / int_base, base);
		last_digit = li_nbr % int_base;
		write_len += write(1, &base[last_digit], 1);
	}
	return (write_len);
}
