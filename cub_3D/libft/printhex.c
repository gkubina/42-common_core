/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:21:22 by gkubina           #+#    #+#             */
/*   Updated: 2023/11/07 17:15:31 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	length(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static int	print_prestring(t_arginfo arginfo, size_t len, char *ox)
{
	int			l;

	l = 0;
	if (arginfo.zeropad && arginfo.width > (int) len)
		l = arginfo.width - len;
	if (arginfo.prec && arginfo.preclen > (int)len)
		l = arginfo.preclen - len;
	if (arginfo.alterf && len > 0 && !(arginfo.is_zero))
	{
		ft_putstr_fd(ox, 1);
		len = len + 2;
	}
	while (!(arginfo.leftad) && arginfo.width > ((int)len + l))
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	while (l)
	{
		ft_putchar_fd('0', 1);
		l--;
		len++;
	}
	return (len);
}

static int	print_poststring(t_arginfo arginfo, size_t len)
{
	while (arginfo.leftad && arginfo.width > (int)len)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	return (len);
}

int	printhex_min(unsigned int i, t_arginfo arginfo)
{
	size_t	len;

	len = length (i);
	if (i == 0)
		arginfo.is_zero = 1;
	if (arginfo.is_zero && arginfo.prec && arginfo.preclen == 0)
		len--;
	len = print_prestring(arginfo, len, "0x");
	if (!(arginfo.is_zero && arginfo.prec && arginfo.preclen == 0))
		ft_putnbr_base_16(i, "0123456789abcdef");
	len = print_poststring(arginfo, len);
	return (len);
}

int	printhex_maj(unsigned int i, t_arginfo arginfo)
{
	size_t	len;

	len = length (i);
	if (i == 0)
		arginfo.is_zero = 1;
	if (arginfo.is_zero && arginfo.prec && arginfo.preclen == 0)
		len--;
	len = print_prestring(arginfo, len, "0X");
	if (!(arginfo.is_zero && arginfo.prec && arginfo.preclen == 0))
		ft_putnbr_base_16(i, "0123456789ABCDEF");
	len = print_poststring(arginfo, len);
	return (len);
}
