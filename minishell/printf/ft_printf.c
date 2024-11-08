/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:21:24 by daleliev          #+#    #+#             */
/*   Updated: 2024/04/08 10:22:37 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

int	ft_search(const char f, va_list ap)
{
	int	len;

	len = 0;
	if (f == 'c')
		len = ft_putchar((char) va_arg(ap, int));
	else if (f == 's')
		len = ft_putstr(va_arg(ap, char *));
	else if (f == 'p')
		len = ft_printp(va_arg(ap, void *), len, 1);
	else if (f == 'd' || f == 'i')
		len = ft_putnbr((long long)va_arg(ap, int), len);
	else if (f == 'u')
		len = ft_putnbru_fd(va_arg(ap, unsigned int), len);
	else if (f == 'x')
		len = ft_printx(va_arg(ap, unsigned int), len);
	else if (f == 'X')
		len = ft_printupperx(va_arg(ap, unsigned int), len);
	else if (f == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			len += ft_search(*(str + 1), ap);
			str++;
		}
		else
		{
			write(1, str, 1);
			len++;
		}
		str++;
	}
	va_end(ap);
	return (len);
}
/*
int main()
{
//char *f = "214748364;
int i = ft_printf("%p %p\n", NULL, NULL);
int j = printf("%p %p\n", NULL, NULL);
printf("%d\n", i);
printf("%d\n", j);
}*/
