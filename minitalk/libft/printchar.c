/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:21:22 by gkubina           #+#    #+#             */
/*   Updated: 2023/11/07 11:36:53 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	printchar(char c, t_arginfo arginfo)
{
	size_t	len;

	len = 1;
	len = print_prestring(arginfo, len);
	ft_putchar_fd(c, 1);
	len = print_poststring(arginfo, len);
	return (len);
}
