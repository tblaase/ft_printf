/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:08:22 by tblaase           #+#    #+#             */
/*   Updated: 2021/07/14 15:38:24 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_str_reverse(char *rev_hexadecimal, char *hexadecimal,
unsigned long long input, t_print *tab)
{
	int		len;
	int		i;

	if (input == 0 && tab->precision == 0)
	{
		hexadecimal[2] = '\0';
		return ;
	}
	i = 2;
	len = ft_strlen(rev_hexadecimal);
	while (len >= 0)
	{
		len--;
		hexadecimal[i] = rev_hexadecimal[len];
		i++;
		if (len == 0)
			break ;
	}
	hexadecimal[i] = '\0';
}

static void	ft_hexa_conversion(unsigned long a, char *convert,
int i, char *rev_hexadecimal)
{
	unsigned long long		b;
	unsigned char			c;

	b = a / 16;
	i++;
	while (a > 9 && b > 0)
	{
		ft_hexa_conversion(b, convert, i, rev_hexadecimal);
		break ;
	}
	c = convert[a % 16];
	rev_hexadecimal[i] = c;
}

static void	ft_pointer_if_else(t_print *tab, char *hexadecimal)
{
	int	len;

	len = ft_strlen(hexadecimal);
	if (tab->width <= len)
		ft_hexadecimal_help_one(tab, len, hexadecimal);
	else if (tab->width > len && !tab->dash)
		ft_hexadecimal_help_two(tab, len, hexadecimal);
	else if (tab->width > len && tab->dash)
		ft_hexadecimal_help_three(tab, len, hexadecimal);
}

void	ft_is_pointer(t_print *tab)
{
	char				*convert;
	char				*rev_hexadecimal;
	char				*hexadecimal;
	int					count;
	unsigned long long	input;

	rev_hexadecimal = ft_calloc(16, sizeof(char));
	if (!rev_hexadecimal)
		return ;
	count = -1;
	convert = "0123456789abcdef";
	input = va_arg(tab->args, unsigned long long);
	ft_hexa_conversion(input, convert, count, rev_hexadecimal);
	hexadecimal = ft_calloc(ft_strlen(rev_hexadecimal) + 3, sizeof(char));
	hexadecimal[0] = '0';
	hexadecimal[1] = 'x';
	ft_str_reverse(rev_hexadecimal, hexadecimal, input, tab);
	ft_pointer_if_else(tab, hexadecimal);
	free (rev_hexadecimal);
	free (hexadecimal);
}
