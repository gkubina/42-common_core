/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printupperx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:32:33 by daleliev          #+#    #+#             */
/*   Updated: 2023/10/30 19:16:01 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printupperx(unsigned int n, int len)
{
	char	*tab;
	int		c;

	tab = "0123456789ABCDEF";
	if (n > 15)
		len = ft_printupperx(n / 16, len);
	c = n % 16;
	write(1, &tab[c], 1);
	len++;
	return (len);
}
/*
int	main()
{
	int i = 12827080585631534761;
	ft_putnbr16(i, 1);
	printf("		 %X", i);
}*/
