/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:21:22 by gkubina           #+#    #+#             */
/*   Updated: 2023/11/07 17:16:39 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_lputstr_fd(char *s, size_t l, int fd)
{
	size_t	i;

	i = 0;
	while (s[i] && i < l)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
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

int	printstr(char *s, t_arginfo arginfo)
{
	size_t	len;
	size_t	l;
	char	*nul;

	nul = "(null)";
	len = 0;
	if (s == NULL)
	{
		s = nul;
		l = ft_strlen(s);
		if (arginfo.prec && arginfo.preclen < 6)
			l = 0;
	}
	else
		l = ft_strlen(s);
	if (arginfo.prec && arginfo.preclen < (int)l)
		l = arginfo.preclen;
	len = print_prestring(arginfo, l);
	ft_lputstr_fd(s, l, 1);
	len = print_poststring(arginfo, len);
	return (len);
}
