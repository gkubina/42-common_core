/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:21:22 by gkubina           #+#    #+#             */
/*   Updated: 2023/11/07 15:14:57 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printarg(t_arginfo arginfo, va_list args)
{
	int	len;

	len = -1;
	if (arginfo.spec == 's')
		len = printstr(va_arg(args, char *), arginfo);
	else if (arginfo.spec == 'i' || arginfo.spec == 'd')
		len = printint(va_arg(args, int), arginfo);
	else if (arginfo.spec == 'u')
		len = printuint(va_arg(args, unsigned int), arginfo);
	else if (arginfo.spec == 'c')
		len = printchar(va_arg(args, int), arginfo);
	else if (arginfo.spec == 'x')
		len = printhex_min(va_arg(args, unsigned int), arginfo);
	else if (arginfo.spec == 'X')
		len = printhex_maj(va_arg(args, unsigned int), arginfo);
	else if (arginfo.spec == 'p')
		len = printpoint(va_arg(args, unsigned long), arginfo);
	else if (arginfo.spec == '%')
		len = printperc();
	if (len == -1)
		return (-1);
	return (arginfo.len + len);
}
