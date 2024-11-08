/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculations_horiz.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/17 15:28:16 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_ya_horiz(double cast_angle)
{
	double	val;

	if (cast_angle > 180)
		val = (double) GRIDSIZE;
	else
		val = -1.0 * (double) GRIDSIZE;
	return (val);
}

double	get_xa_horiz(double cast_angle)
{
	double	x_a;

	x_a = -1 * get_ya_horiz(cast_angle) / tan_degrees(cast_angle);
	return (x_a);
}

t_coord	first_horiz_inter(t_coord *position, double cast_angle)
{
	t_coord	intersection;

	cast_angle = angle_360(cast_angle);
	if (cast_angle == 0 || cast_angle == 180)
	{
		intersection.x = position->x;
		intersection.y = position->y;
	}
	else if (cast_angle < 180)
	{
		intersection.y = (((int)position->y / GRIDSIZE) * GRIDSIZE) - OFFSET;
		intersection.x = (position->y - intersection.y)
			/ tan_degrees(cast_angle) + position->x;
	}
	else
	{
		intersection.y = (((int)position->y / GRIDSIZE) * GRIDSIZE) + GRIDSIZE;
		intersection.x = (position->y - intersection.y)
			/ tan_degrees(cast_angle) + position->x;
	}
	return (intersection);
}

t_coord	find_horiz_inter(t_cub *c3d, t_coord *position, double cast_angle)
{
	t_coord	intersection;
	int		maxtest;

	maxtest = -1;
	intersection = first_horiz_inter(position, cast_angle);
	while (++maxtest < MAXTEST)
	{
		if (!(intersection.x > 0 && intersection.x < c3d->map->size_x
				&& intersection.y > 0 && intersection.y < c3d->map->size_y))
			return (intersection);
		else if (intersection.x > 0 && intersection.x < c3d->map->size_x
			&& intersection.y > 0
			&& intersection.y < c3d->map->size_y
			&& c3d->map->coord
			[(int)floor(intersection.x)]
			[(int)floor(intersection.y)] > 0)
			return (intersection);
		else
		{
			intersection.x = intersection.x + get_xa_horiz(cast_angle);
			intersection.y = intersection.y + get_ya_horiz(cast_angle);
		}
	}
	return (intersection);
}
