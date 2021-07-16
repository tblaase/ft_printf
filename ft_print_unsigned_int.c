/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:06:17 by tblaase           #+#    #+#             */
/*   Updated: 2021/07/13 15:23:25 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prec_greater_unsigned_intlen(t_print *tab, int len, unsigned int u)
{
	int	i;

	i = tab->precision - len;
	while (i > 0)
	{
		write(1, &"0", 1);
		i--;
	}
	ft_put_unsigned_nbr(u);
	tab->printlen = tab->printlen + tab->precision;
}

void	ft_is_unsigned_int(t_print *tab)
{
	unsigned int	u;
	int				len;

	u = va_arg(tab->args, unsigned int);
	len = ft_unsigned_intlen(u);
	if (tab->precision <= len && tab->width > len && tab->precision != -1)
		tab->zero = 0;
	if (tab->precision == 0 && u == 0)
		ft_special_zero(tab);
	else if (tab->width <= len)
		ft_unsigned_int_help_one(tab, len, u);
	else if (!tab->zero && !tab->dash && tab->width > len)
		ft_unsigned_int_help_two(tab, len, u);
	else if (tab->dash && tab->width > len)
		ft_unsigned_int_help_three(tab, len, u);
	else if (tab->zero && tab->width > len && tab->precision <= len)
		ft_unsigned_int_help_four(tab, len, u);
	else if (tab->zero && tab->width > len && tab->precision > len)
		ft_unsigned_int_help_five(tab, len, u);
}
