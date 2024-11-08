/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:21:22 by gkubina           #+#    #+#             */
/*   Updated: 2023/11/07 14:28:13 by gkubina          ###   ########.fr       */
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
		n = n / 10;
	}
	return (len);
}

static int	print_prestring(t_arginfo arginfo, size_t len)
{
	int			l;

	l = 0;
	if (arginfo.zeropad && arginfo.width > (int) len)
		l = arginfo.width - len;
	if (arginfo.prec && arginfo.preclen > (int)len)
		l = arginfo.preclen - len;
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

int	printuint(unsigned int i, t_arginfo arginfo)
{
	size_t	len;

	len = length (i);
	if (i == 0 && arginfo.prec && arginfo.preclen == 0)
		len--;
	len = print_prestring(arginfo, len);
	if (!(i == 0 && arginfo.prec && arginfo.preclen == 0))
		ft_putnbr_unsig_fd(i, 1);
	len = print_poststring(arginfo, len);
	return ((int)len);
}
