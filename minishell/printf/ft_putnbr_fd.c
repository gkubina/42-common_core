/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:58:03 by daleliev          #+#    #+#             */
/*   Updated: 2024/04/08 10:23:26 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putnbr(long long n, int len)
{
	unsigned long long	nb;
	char				c;

	if (n < 0)
	{
		write(1, "-", 1);
		nb = (unsigned long long)(-n);
		len++;
	}
	else
		nb = (unsigned long long)n;
	if (nb > 9)
		len = ft_putnbr(nb / 10, len);
	c = (char)(nb % 10 + '0');
	write(1, &c, 1);
	len++;
	return (len);
}

int	ft_putnbru_fd(unsigned long long n, int len)
{
	char				c;

	if (n > 9)
		len = ft_putnbr(n / 10, len);
	c = (char)(n % 10 + '0');
	write(1, &c, 1);
	len++;
	return (len);
}
