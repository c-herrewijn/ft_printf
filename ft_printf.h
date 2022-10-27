/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/22 15:32:19 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/10/27 17:15:23 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		get_nr_formats(const char *format_str, char *format_chars);
size_t	ft_putnbr_base(long long int nbr, char *base);
void	ft_putpointer(unsigned long long nbr, int *print_len);
void	ft_putunsnr(unsigned int nbr, int *print_len);
void	ft_putunsignedhex(unsigned int nbr, int *print_len, char var_case);

#endif
