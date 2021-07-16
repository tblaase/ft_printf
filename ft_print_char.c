/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 09:49:02 by tblaase           #+#    #+#             */
/*   Updated: 2021/07/13 15:28:25 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_is_char(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	if (tab->width > 1 && !tab->dash)
		ft_width_right(tab, 1);
	tab->printlen = tab->printlen + write(1, &a, 1);
	if (tab->width > 1 && tab->dash)
		ft_width_right(tab, 1);
}

void	ft_is_percent(t_print *tab)
{
	char	a;

	a = '%';
	if (tab->dash)
		tab->zero = 0;
	if (tab->width > 1 && !tab->dash)
		ft_width_right(tab, 1);
	tab->printlen = tab->printlen + write(1, &a, 1);
	if (tab->width > 1 && tab->dash)
		ft_width_right(tab, 1);
}
