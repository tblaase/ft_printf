/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_intlen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:36:13 by tblaase           #+#    #+#             */
/*   Updated: 2021/07/12 14:59:08 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_unsigned_intlen(unsigned int a)
{
	int	i;

	i = 0;
	if (a >= 0 && a <= 9)
		return (1);
	while (a > 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}
