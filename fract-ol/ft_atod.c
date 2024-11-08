/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:47:40 by gkubina           #+#    #+#             */
/*   Updated: 2024/02/06 11:39:38 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

static double	decimals(const char *nptr)
{
	unsigned int	i;
	double			j;
	double			resultat;

	i = 0;
	j = 10;
	resultat = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		resultat = resultat + (double)(nptr[i] - '0') / j;
		i++;
		j = j * 10;
	}
	return (resultat);
}

double	ft_atod(const char *nptr)
{
	unsigned int	i;
	double			negative;
	double			resultat;

	i = 0;
	negative = 1;
	resultat = 0;
	if (nptr[i] == '-')
	{
		negative = negative * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		resultat = (resultat * 10) + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] == '.')
	{
		i++;
		resultat = resultat + decimals(nptr + i);
	}
	return (resultat * negative);
}
