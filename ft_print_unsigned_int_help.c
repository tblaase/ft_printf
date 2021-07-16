/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int_help.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:32:41 by tblaase           #+#    #+#             */
/*   Updated: 2021/07/12 13:22:55 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_unsigned_int_help_one(t_print *tab, int len, unsigned int u)
{
	if (tab->precision > len)
		ft_prec_greater_unsigned_intlen(tab, len, u);
	else
	{
		ft_put_unsigned_nbr(u);
		tab->printlen = tab->printlen + len;
	}
}

void	ft_unsigned_int_help_two(t_print *tab, int len, unsigned int u)
{
	if (tab->precision > len)
	{
		ft_width_right(tab, tab->precision);
		ft_prec_greater_unsigned_intlen(tab, len, u);
	}
	else
	{
		tab->zero = 0;
		ft_width_right(tab, len);
		ft_put_unsigned_nbr(u);
		tab->printlen = tab->printlen + len;
	}
}

void	ft_unsigned_int_help_three(t_print *tab, int len, unsigned int u)
{
	if (tab->precision > len)
	{
		ft_prec_greater_unsigned_intlen(tab, len, u);
		ft_width_left(tab, tab->precision);
	}
	else
	{
		ft_put_unsigned_nbr(u);
		ft_width_left(tab, len);
		tab->printlen = tab->printlen + len;
	}
}

void	ft_unsigned_int_help_four(t_print *tab, int len, unsigned int u)
{
	tab->precision = tab->width;
	ft_prec_greater_unsigned_intlen(tab, len, u);
}

void	ft_unsigned_int_help_five(t_print *tab, int len, unsigned int u)
{
	tab->zero = 0;
	ft_width_right(tab, tab->precision);
	ft_prec_greater_unsigned_intlen(tab, len, u);
}
