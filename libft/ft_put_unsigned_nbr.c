/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:42:21 by tblaase           #+#    #+#             */
/*   Updated: 2021/07/09 15:11:30 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_unsigned_nbr(unsigned int u)
{
	char	c;

	if (u >= 10)
	{
		ft_put_unsigned_nbr(u / 10);
		ft_put_unsigned_nbr(u % 10);
	}
	else
	{
		c = u + '0';
		write(1, &c, 1);
	}
}
