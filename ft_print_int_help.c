/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:54:40 by tblaase           #+#    #+#             */
/*   Updated: 2021/07/14 14:18:42 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_int_help_one(t_print *tab, int len, int z)
{
	if (tab->precision > len)
		ft_prec_greater_intlen(tab, len, z);
	else
	{
		ft_putnbr_fd(z, 1);
		tab->printlen = tab->printlen + len;
	}
}

void	ft_int_help_two(t_print *tab, int len, int z)
{
	if (tab->precision > len)
	{
		if (z < 0)
			tab->precision++;
		ft_width_right(tab, tab->precision);
		if (z < 0)
			tab->precision--;
		ft_prec_greater_intlen(tab, len, z);
	}
	else
	{
		tab->zero = 0;
		ft_width_right(tab, len);
		ft_putnbr_fd(z, 1);
		tab->printlen = tab->printlen + len;
	}
}

void	ft_int_help_three(t_print *tab, int len, int z)
{
	if (tab->precision > len)
	{
		ft_prec_greater_intlen(tab, len, z);
		if (z < 0)
			tab->precision++;
		ft_width_left(tab, tab->precision);
	}
	else
	{
		ft_putnbr_fd(z, 1);
		ft_width_right(tab, len);
		tab->printlen = tab->printlen + len;
	}
}

void	ft_int_help_four(t_print *tab, int len, int z)
{
	if (z < 0 && tab->precision == -1)
	{
		write(1, &"-", 1);
		z = z * -1;
	}
	if (tab->precision != -1)
		tab->zero = 0;
	ft_width_right(tab, len);
	ft_putnbr_fd(z, 1);
	tab->printlen = tab->printlen + len;
}

void	ft_int_help_five(t_print *tab, int len, int z)
{
	tab->zero = 0;
	if (z < 0)
		tab->precision++;
	ft_width_right(tab, tab->precision);
	if (z < 0)
		tab->precision--;
	ft_prec_greater_intlen(tab, len, z);
}
