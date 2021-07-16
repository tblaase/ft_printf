/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:03:34 by tblaase           #+#    #+#             */
/*   Updated: 2021/07/13 15:34:19 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_precision_str_helper(t_print *tab, char *str, int len, int i)
{
	if (tab->precision < tab->width && tab->dash)
	{
		while (i < len)
		{
			tab->printlen = tab->printlen + write(1, &str[i], 1);
			i++;
		}
		while (i < tab->width)
		{
			tab->printlen = tab->printlen + write(1, &" ", 1);
			i++;
		}
	}
	else
	{
		while (i < tab->precision)
		{
			tab->printlen = tab->printlen + write(1, &str[i], 1);
			i++;
		}
	}
}

static void	ft_precision_str(t_print *tab, char *str)
{
	int		i;
	int		c;
	int		len;

	i = 0;
	c = 0;
	len = (int)ft_strlen(str);
	if (len > tab->precision)
		len = tab->precision;
	if (tab->precision < tab->width && !tab->dash)
	{
		while (i < (tab->width - len))
		{
			tab->printlen = tab->printlen + write(1, &" ", 1);
			i++;
		}
		while (i < tab->width)
		{
			tab->printlen = tab->printlen + write(1, &str[c], 1);
			c++;
			i++;
		}
	}
	ft_precision_str_helper(tab, str, len, i);
}

static void	ft_is_string_help(t_print *tab, int len, char *str)
{
	if (tab->width > len && !tab->dash)
	{
		ft_width_right(tab, len);
		tab->printlen = tab->printlen + ft_putstr_fd(str, 1);
	}
	else if (tab->width > len && tab->dash)
	{
		tab->printlen = tab->printlen + ft_putstr_fd(str, 1);
		ft_width_left(tab, len);
	}
	else
		tab->printlen = tab->printlen + ft_putstr_fd(str, 1);
}

void	ft_is_string(t_print *tab)
{
	char	*str;
	int		len;

	str = va_arg(tab->args, char *);
	if (!str)
	{
		str = "(null)";
	}
	len = ft_strlen(str);
	if ((tab->precision >= len || tab->precision == -1) && tab->width <= len)
		tab->printlen = tab->printlen + ft_putstr_fd(str, 1);
	else if (tab->precision < len && tab->precision > 0)
		ft_precision_str(tab, str);
	else if (tab->precision == 0)
	{
		ft_width_right(tab, 0);
		return ;
	}
	else
		ft_is_string_help(tab, len, str);
}
