/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:08:46 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/31 09:08:52 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printx(unsigned int n, int len)
{
	char	*tab;
	int		c;

	tab = "0123456789abcdef";
	if (n > 15)
		len = ft_printx(n / 16, len);
	c = n % 16;
	write(1, &tab[c], 1);
	len++;
	return (len);
}
