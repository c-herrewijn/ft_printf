/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/22 15:32:19 by cherrewi      #+#    #+#                 */
/*   Updated: 2022/10/27 18:10:18 by cherrewi      ########   odam.nl         */
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
void	printf_putstr(char *str, int *print_len);
void	printf_putnbr(int n, int *print_len);
void	printf_putunsnbr(unsigned int nbr, int *print_len);
void	printf_putpointer(unsigned long long nbr, int *print_len);
void	printf_putunsignedhex(unsigned int nbr, int *print_len, char var_case);

#endif
