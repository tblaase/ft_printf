/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 08:54:40 by tblaase           #+#    #+#             */
/*   Updated: 2021/07/13 15:27:02 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_check_zero(t_print *tab)
{
	if (tab->dash)
		tab->zero = 0;
}

static int	ft_get_argument(t_print *tab, const char *format, int i)
{
	if (format[i] == 'c')
		ft_is_char(tab);
	else if (format[i] == 's')
		ft_is_string(tab);
	else if (format[i] == 'p')
		ft_is_pointer(tab);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_is_int(tab);
	else if (format[i] == 'u')
		ft_is_unsigned_int(tab);
	else if (format[i] == 'x' || format[i] == 'X')
		ft_is_hexadecimal(tab, format, i);
	else if (format[i] == '%')
		ft_is_percent(tab);
	i++;
	return (i);
}

int	ft_get_format(t_print *tab, const char *format, int i)
{
	while (!(ft_isalpha(format[i]) || format[i] == '%'))
	{
		if (format[i] == '-')
			i = ft_dash(tab, format, i);
		if (format[i] == '0')
			i = ft_zero(tab, format, i);
		if (ft_isdigit(format[i]))
			i = ft_width(tab, format, i);
		if (format[i] == '.')
			i = ft_precision(tab, format, i);
	}
	ft_check_zero(tab);
	i = ft_get_argument(tab, format, i);
	ft_reset_tab(tab);
	return (i);
}
