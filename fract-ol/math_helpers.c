/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/02/06 10:58:19 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_abs(double a, double b)
{
	if (a < b)
		return (b - a);
	return (a - b);
}

t_complex	init_complex(void)
{
	t_complex	new;

	new.r = 0.0;
	new.i = 0.0;
	return (new);
}

t_complex	calc_complex(t_complex comp_1, t_complex comp_2, int operator)
{
	t_complex	result;

	if (operator == COMPL_ADD)
	{
		result.r = comp_1.r + comp_2.r;
		result.i = comp_1.i + comp_2.i;
	}
	else if (operator == COMPL_MUL)
	{
		result.r = ((comp_1.r * comp_2.r) - (comp_1.i * comp_2.i));
		result.i = ((comp_1.r * comp_2.i) + (comp_1.i * comp_2.r));
	}
	else if (operator == COMPL_SUB)
	{
		result.r = comp_1.r - comp_2.r;
		result.i = comp_1.i - comp_2.i;
	}
	else if (operator == COMPL_DIV)
	{
		result.r = ((comp_1.r * comp_2.r) + (comp_1.i * comp_2.i))
			/ ((comp_2.r * comp_2.r) + (comp_2.i * comp_2.i));
		result.i = ((comp_2.r * comp_1.i) - (comp_1.r * comp_2.i))
			/ ((comp_2.r * comp_2.r) + (comp_2.i * comp_2.i));
	}
	return (result);
}
