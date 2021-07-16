/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:05:23 by tblaase           #+#    #+#             */
/*   Updated: 2021/07/14 15:29:43 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned int	ft_int_neg(int z)
{
	unsigned int	a;

	a = (unsigned int)z * -1;
	write(1, &"-", 1);
	return (a);
}

void	ft_prec_greater_intlen(t_print *tab, int len, int z)
{
	int				i;
	unsigned int	a;

	i = tab->precision - len;
	if (z < 0)
	{
		a = ft_int_neg(z);
		i++;
	}
	while (i > 0)
	{
		tab->printlen = tab->printlen + write(1, &"0", 1);
		i--;
	}
	if (z < 0)
		ft_put_unsigned_nbr(a);
	else
		ft_putnbr_fd(z, 1);
	tab->printlen = tab->printlen + len;
}

static void	ft_special_int(t_print *tab, int len, int z)
{
	tab->zero = 0;
	if (!tab->dash || tab->width > len)
		ft_width_right(tab, len + 1);
	len--;
	write(1, &"-", 1);
	z = z * -1;
	while (tab->precision > len)
	{
		tab->printlen = tab->printlen + write(1, &"0", 1);
		len++;
	}
	ft_putnbr_fd(z, 1);
	tab->printlen = tab->printlen + len;
	if (tab->dash)
		ft_width_left(tab, len);
}

void	ft_is_int(t_print *tab)
{
	int	z;
	int	len;

	z = va_arg(tab->args, int);
	len = ft_intlen(z);
	if (z < 0)
		len++;
	if (tab->precision > tab->width)
		tab->width = tab->precision;
	if (tab->precision == 0 && z == 0)
		ft_special_zero(tab);
	else if (z < 0 && tab->precision == len)
		ft_special_int(tab, len, z);
	else if (tab->zero && tab->width > len && tab->precision <= len)
		ft_int_help_four(tab, len, z);
	else if (tab->zero && tab->width > len && tab->precision > len)
		ft_int_help_five(tab, len, z);
	else if (tab->dash && tab->width > len)
		ft_int_help_three(tab, len, z);
	else if (!tab->zero && !tab->dash && tab->width > len)
		ft_int_help_two(tab, len, z);
	else if (tab->width <= len)
		ft_int_help_one(tab, len, z);
}
