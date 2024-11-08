/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arginfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:24:40 by gkubina           #+#    #+#             */
/*   Updated: 2023/11/09 09:03:36 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	is_flag(char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

static t_arginfo	parse_flag(const char c, t_arginfo old)
{
	t_arginfo	arginfo;

	arginfo = old;
	if (c == '0')
		arginfo.zeropad = 1;
	if (c == '-')
		arginfo.leftad = 1;
	if (c == '#')
		arginfo.alterf = 1;
	if (c == '+')
		arginfo.sign = 1;
	if (c == ' ')
		arginfo.blank = 1;
	return (arginfo);
}

static t_arginfo	clean_arginfo(t_arginfo old)
{
	t_arginfo	arginfo;

	arginfo = old;
	if (arginfo.zeropad && (arginfo.leftad || arginfo.prec))
		arginfo.zeropad = 0;
	if (arginfo.blank && arginfo.sign)
		arginfo.blank = 0;
	if (arginfo.preclen < 0)
	{
		arginfo.prec = 0;
		arginfo.preclen = 0;
	}
	arginfo.count++;
	return (arginfo);
}

t_arginfo	fill_arginfo(const char *s, t_arginfo old)
{
	t_arginfo	arginfo;

	arginfo = old;
	while (s[++arginfo.count] && is_flag(s[arginfo.count]))
		arginfo = parse_flag(s[arginfo.count], arginfo);
	if (ft_isdigit(s[arginfo.count]))
	{
		arginfo.width = ft_atoi(s + arginfo.count);
		arginfo.count += (intlength(arginfo.width));
	}
	if (s[arginfo.count] == '.')
	{
		arginfo.prec = 1;
		arginfo.count++;
	}
	while (s[arginfo.count] == '0')
		arginfo.count++;
	if (ft_isdigit(s[arginfo.count]) && arginfo.prec == 1)
	{
		arginfo.preclen = ft_atoi(s + arginfo.count);
		arginfo.count += (intlength(arginfo.preclen));
	}
	if (is_specifier(s[arginfo.count]))
		arginfo.spec = s[arginfo.count];
	return (clean_arginfo(arginfo));
}
