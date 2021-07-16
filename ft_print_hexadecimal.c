/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:07:20 by tblaase           #+#    #+#             */
/*   Updated: 2021/07/14 15:44:44 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_str_reverse(char *rev_hexadecimal, char *hexadecimal)
{
	int		len;
	int		i;

	i = 0;
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

static void	ft_hexa_conversion(unsigned int a, char *convert,
int i, char *rev_hexadecimal)
{
	int		b;
	char	c;

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

void	ft_prec_greater_hexa_len(t_print *tab,
int len, char *hexadecimal)
{
	int	i;

	i = tab->precision - len;
	while (i > 0)
	{
		write(1, &"0", 1);
		i--;
	}
	ft_putstr_fd(hexadecimal, 1);
	tab->printlen = tab->printlen + tab->precision;
}

static void	ft_hexa_if_else(t_print *tab, char *hexadecimal)
{
	int	len;

	len = ft_strlen(hexadecimal);
	if (tab->precision > len)
		tab->zero = 0;
	if (tab->precision == 0 && hexadecimal[0] == '0' && len == 1)
		ft_special_zero(tab);
	else if (tab->width <= len)
		ft_hexadecimal_help_one(tab, len, hexadecimal);
	else if (!tab->zero && !tab->dash && tab->width > len)
		ft_hexadecimal_help_two(tab, len, hexadecimal);
	else if (tab->dash && tab->width > len)
		ft_hexadecimal_help_three(tab, len, hexadecimal);
	else if (tab->zero && tab->width > len && tab->precision <= len)
		ft_hexadecimal_help_four(tab, len, hexadecimal);
	else if (tab->zero && tab->width > len && tab->precision > len)
		ft_hexadecimal_help_five(tab, len, hexadecimal);
}

void	ft_is_hexadecimal(t_print *tab, const char *format, int i)
{
	char	*convert;
	char	*rev_hexadecimal;
	char	*hexadecimal;
	int		count;

	rev_hexadecimal = ft_calloc(9, sizeof(char));
	if (!rev_hexadecimal)
		return ;
	count = -1;
	if (format[i] == 'X')
		convert = "0123456789ABCDEF";
	else
		convert = "0123456789abcdef";
	ft_hexa_conversion(va_arg(tab->args, unsigned int),
		convert, count, rev_hexadecimal);
	hexadecimal = ft_calloc(ft_strlen(rev_hexadecimal) + 1, sizeof(char));
	ft_str_reverse(rev_hexadecimal, hexadecimal);
	ft_hexa_if_else(tab, hexadecimal);
	free (rev_hexadecimal);
	free (hexadecimal);
}
