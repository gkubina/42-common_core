/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculations_vert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/17 15:28:23 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_xa_vert(double cast_angle)
{
	double	val;

	if (cast_angle < 90 || cast_angle > 270)
		val = (double) GRIDSIZE;
	else
		val = -1.0 * (double) GRIDSIZE;
	return (val);
}

double	get_ya_vert(double cast_angle)
{
	double	y_a;

	y_a = -1 * get_xa_vert(cast_angle) * tan_degrees(cast_angle);
	return (y_a);
}

t_coord	first_vert_inter(t_coord *position, double cast_angle)
{
	t_coord	intersection;

	cast_angle = angle_360(cast_angle);
	if (cast_angle == 90 || cast_angle == 270)
	{
		intersection.x = position->x;
		intersection.y = position->y;
	}
	else if (cast_angle < 90 || cast_angle > 270)
	{
		intersection.x = (((int)position->x / GRIDSIZE) * GRIDSIZE) + GRIDSIZE;
		intersection.y = (position->x - intersection.x)
			* tan_degrees(cast_angle) + position->y;
	}
	else
	{
		intersection.x = (((int)position->x / GRIDSIZE) * GRIDSIZE) - OFFSET;
		intersection.y = (position->x - intersection.x)
			* tan_degrees(cast_angle) + position->y;
	}
	return (intersection);
}

t_coord	find_vert_inter(t_cub *c3d, t_coord *position, double cast_angle)
{
	t_coord	intersection;
	int		maxtest;

	maxtest = -1;
	intersection = first_vert_inter(position, cast_angle);
	while (++maxtest < MAXTEST)
	{
		if (!(intersection.x > 0 && intersection.x < c3d->map->size_x
				&& intersection.y > 0 && intersection.y < c3d->map->size_y))
			return (intersection);
		else if (intersection.x > 0 && intersection.x < c3d->map->size_x
			&& intersection.y > 0 && intersection.y < c3d->map->size_y
			&& c3d->map->coord
			[(int)floor(intersection.x)]
			[(int)floor(intersection.y)] > 0)
			return (intersection);
		else
		{
			intersection.x = intersection.x + get_xa_vert(cast_angle);
			intersection.y = intersection.y + get_ya_vert(cast_angle);
		}
	}
	return (intersection);
}
