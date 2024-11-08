/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:00:05 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/31 15:20:17 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printp(void *f, int len, int b)
{
	unsigned long long	val;
	char				*tab;
	int					c;

	val = (unsigned long long) f;
	tab = "0123456789abcdef";
	if (val == '\0')
	{
		write (1, "(nil)", 5);
		return (5);
	}
	if (b == 1)
	{
		write (1, "0x", 2);
		b = 0;
		len += 2;
	}
	if (val > 15)
		len = ft_printp((void *)(val / 16), len, b);
	c = val % 16;
	write(1, &tab[c], 1);
	len++;
	return (len);
}
