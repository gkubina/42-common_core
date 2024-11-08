/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/04 16:29:56 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	absolute_int(int a, int b)
{
	if (a < b)
		return (b - a);
	return (a - b);
}

double	absolute_doub(double a, double b)
{
	if (a < b)
		return (b - a);
	return (a - b);
}

double	tan_degrees(double x)
{
	double	radians;

	radians = x * (MY_PI / 180.0);
	return (tan(radians));
}

double	cos_degrees(double x)
{
	double	radians;

	radians = x * (MY_PI / 180.0);
	return (cos(radians));
}

double	sin_degrees(double x)
{
	double	radians;

	radians = x * (MY_PI / 180.0);
	return (sin(radians));
}
