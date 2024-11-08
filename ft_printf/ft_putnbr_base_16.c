/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_16.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:21:22 by gkubina           #+#    #+#             */
/*   Updated: 2023/11/07 11:35:38 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_base_16(unsigned int nbr, char *base)
{
	if (nbr < 16)
	{
		ft_putchar_fd(base[nbr], 1);
	}
	else
	{
		ft_putnbr_base_16(nbr / 16, base);
		ft_putnbr_base_16(nbr % 16, base);
	}
}
