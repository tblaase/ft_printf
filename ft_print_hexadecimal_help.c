/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal_help.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:38:31 by tblaase           #+#    #+#             */
/*   Updated: 2021/07/14 15:44:41 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_hexadecimal_help_one(t_print *tab, int len, char *hexadecimal)
{
	if (tab->precision > len)
		ft_prec_greater_hexa_len(tab, len, hexadecimal);
	else
		tab->printlen = tab->printlen + ft_putstr_fd(hexadecimal, 1);
}

void	ft_hexadecimal_help_two(t_print *tab, int len, char *hexadecimal)
{
	if (tab->precision > len)
	{
		ft_width_right(tab, tab->precision);
		ft_prec_greater_hexa_len(tab, len, hexadecimal);
	}
	else
	{
		tab->zero = 0;
		ft_width_right(tab, len);
		tab->printlen = tab->printlen + ft_putstr_fd(hexadecimal, 1);
	}
}

void	ft_hexadecimal_help_three(t_print *tab, int len, char *hexadecimal)
{
	if (tab->precision > len)
	{
		ft_prec_greater_hexa_len(tab, len, hexadecimal);
		ft_width_left(tab, tab->precision);
	}
	else
	{
		tab->printlen = tab->printlen + ft_putstr_fd(hexadecimal, 1);
		ft_width_right(tab, len);
	}
}

void	ft_hexadecimal_help_four(t_print *tab, int len, char *hexadecimal)
{
	if (tab->precision != -1)
		tab->zero = 0;
	ft_width_right(tab, len);
	tab->printlen = tab->printlen + ft_putstr_fd(hexadecimal, 1);
}

void	ft_hexadecimal_help_five(t_print *tab, int len, char *hexadecimal)
{
	tab->zero = 0;
	ft_width_right(tab, tab->precision);
	ft_prec_greater_hexa_len(tab, len, hexadecimal);
}
