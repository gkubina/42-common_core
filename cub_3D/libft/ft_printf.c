/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:22:13 by gkubina           #+#    #+#             */
/*   Updated: 2023/11/07 17:31:29 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_arginfo	arginfo;

	arginfo = init_arginfo();
	va_start(args, format);
	while (format[arginfo.count] && arginfo.len != -1)
	{
		if (format[arginfo.count] == '%')
		{
			arginfo = fill_arginfo(format, arginfo);
			arginfo.len = ft_printarg(arginfo, args);
			if (arginfo.len == -1)
				break ;
			arginfo = reset_flags(arginfo);
		}
		else
		{
			ft_putchar_fd(format[arginfo.count], 1);
			arginfo.len++;
			arginfo.count++;
		}
	}
	va_end(args);
	return (arginfo.len);
}
