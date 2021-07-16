/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 09:55:46 by tblaase           #+#    #+#             */
/*   Updated: 2021/07/13 15:22:42 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_dash(t_print *tab, const char *format, int i)
{
	tab->dash = 1;
	while (format[i] == '-')
		i++;
	return (i);
}

int	ft_precision(t_print *tab, const char *format, int i)
{
	int	n;

	tab->precision = 0;
	i++;
	if (!ft_isdigit(format[i]))
		return (i);
	while (format[i] == '0')
		i++;
	if (ft_isdigit(format[i]))
	{
		n = ft_atoi(&format[i]);
		tab->precision = n;
		i = i + ft_intlen(n);
	}
	return (i);
}

int	ft_zero(t_print *tab, const char *format, int i)
{
	tab->zero = 1;
	while (format[i] == '0')
		i++;
	return (i);
}

int	ft_width(t_print *tab, const char *format, int i)
{
	int	n;

	n = ft_atoi(&format[i]);
	tab->width = n;
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}
