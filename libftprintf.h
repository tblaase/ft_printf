/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:01:22 by tblaase           #+#    #+#             */
/*   Updated: 2021/07/14 15:44:27 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_print
{
	va_list	args;
	int		width;
	int		precision;
	int		zero;
	int		dash;
	int		printlen;
	int		percent;
}				t_print;

int		ft_printf(const char *format, ...);
int		ft_get_format(t_print *tab, const char *format, int i);
int		ft_dash(t_print *tab, const char *format, int i);
int		ft_precision(t_print *tab, const char *format, int i);
int		ft_zero(t_print *tab, const char *format, int i);
int		ft_width(t_print *tab, const char *format, int i);

void	ft_special_zero(t_print *tab);
void	ft_is_char(t_print *tab);
void	ft_is_percent(t_print *tab);
void	ft_is_string(t_print *tab);
void	ft_is_int(t_print *tab);
void	ft_is_unsigned_int(t_print *tab);
void	ft_is_hexadecimal(t_print *tab, const char *format, int i);
void	ft_is_pointer(t_print *tab);
void	ft_control_flags(t_print *tab);
void	ft_width_right(t_print *tab, int len);
void	ft_width_left(t_print *tab, int len);
void	ft_prec_greater_intlen(t_print *tab, int len, int z);
void	ft_int_help_one(t_print *tab, int len, int z);
void	ft_int_help_two(t_print *tab, int len, int z);
void	ft_int_help_three(t_print *tab, int len, int z);
void	ft_int_help_four(t_print *tab, int len, int z);
void	ft_int_help_five(t_print *tab, int len, int z);
void	ft_prec_greater_unsigned_intlen(t_print *tab, int len, unsigned int u);
void	ft_unsigned_int_help_one(t_print *tab, int len, unsigned int u);
void	ft_unsigned_int_help_two(t_print *tab, int len, unsigned int u);
void	ft_unsigned_int_help_three(t_print *tab, int len, unsigned int u);
void	ft_unsigned_int_help_four(t_print *tab, int len, unsigned int u);
void	ft_unsigned_int_help_five(t_print *tab, int len, unsigned int u);
void	ft_prec_greater_hexa_len(t_print *tab, int len, char *hexadecimal);
void	ft_hexadecimal_help_one(t_print *tab, int len, char *hexadecimal);
void	ft_hexadecimal_help_two(t_print *tab, int len, char *hexadecimal);
void	ft_hexadecimal_help_three(t_print *tab, int len, char *hexadecimal);
void	ft_hexadecimal_help_four(t_print *tab, int len, char *hexadecimal);
void	ft_hexadecimal_help_five(t_print *tab, int len, char *hexadecimal);

t_print	*ft_init_tab(t_print *tab);
t_print	*ft_reset_tab(t_print *tab);

#endif
