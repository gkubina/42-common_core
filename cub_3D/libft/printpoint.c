/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:21:22 by gkubina           #+#    #+#             */
/*   Updated: 2023/11/07 11:38:25 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	length(unsigned long n)
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

static void	ft_putptr_base_16(unsigned long nbr, char *base)
{
	if (nbr < 16)
	{
		ft_putchar_fd(base[nbr], 1);
	}
	else
	{
		ft_putptr_base_16(nbr / 16, base);
		ft_putptr_base_16(nbr % 16, base);
	}
}

static int	print_prestring(t_arginfo arginfo, size_t len)
{
	while (!(arginfo.leftad) && arginfo.width > (int)len)
	{
		ft_putchar_fd(' ', 1);
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

int	printpoint(unsigned long i, t_arginfo arginfo)
{
	size_t	len;

	if (i == 0)
		len = printstr("(nil)", arginfo);
	else
	{
		len = length (i) + 2;
		len = print_prestring(arginfo, len);
		ft_putstr_fd("0x", 1);
		ft_putptr_base_16(i, "0123456789abcdef");
		len = print_poststring(arginfo, len);
	}
	return (len);
}
