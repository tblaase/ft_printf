/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:06:51 by tblaase           #+#    #+#             */
/*   Updated: 2021/07/13 15:34:16 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_print	*ft_init_tab(t_print *tab)
{
	tab->width = 0;
	tab->precision = -1;
	tab->zero = 0;
	tab->dash = 0;
	tab->printlen = 0;
	tab->percent = 0;
	return (tab);
}

t_print	*ft_reset_tab(t_print *tab)
{
	tab->width = 0;
	tab->precision = -1;
	tab->zero = 0;
	tab->dash = 0;
	tab->percent = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	t_print	*tab;
	int		ret;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (0);
	ft_init_tab(tab);
	va_start(tab->args, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_get_format(tab, format, i + 1);
		else
		{
			ret = ret + write(1, &format[i], 1);
			i++;
		}
	}
	va_end(tab->args);
	ret = ret + tab->printlen;
	free (tab);
	return (ret);
}
