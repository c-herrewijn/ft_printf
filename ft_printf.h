/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cherrewi <cherrewi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/22 15:32:19 by cherrewi      #+#    #+#                 */
/*   Updated: 2023/02/08 15:54:31 by cherrewi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
void	printf_putstr(char *str, int *print_len);
void	printf_putnbr(int n, int *print_len);
void	printf_putunsnbr(unsigned int nbr, int *print_len);
void	printf_putunsignedhex(unsigned long long nbr, int *print_len, char var_case);

#endif
