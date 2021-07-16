/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:01:18 by tblaase           #+#    #+#             */
/*   Updated: 2021/07/14 15:44:39 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_width_right(t_print *tab, int len)
{
	char	c;

	if (!tab->zero)
		c = ' ';
	else
		c = '0';
	if (tab->width > len)
	{
		while (tab->width > len)
		{
			tab->printlen = tab->printlen + write(1, &c, 1);
			len++;
		}
	}
}

void	ft_width_left(t_print *tab, int len)
{
	char	c;

	if (!tab->zero)
		c = ' ';
	else
		c = '0';
	if (tab->width > tab->printlen)
	{
		while (tab->width > len)
		{
			tab->printlen = tab->printlen + write(1, &c, 1);
			len++;
		}
	}
}
