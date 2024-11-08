/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/24 12:42:18 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	angle_360(double angle)
{
	while (angle >= 360)
		angle = angle - 360;
	while (angle < 0)
		angle = angle + 360;
	return (angle);
}

double	distance_points(t_cub *c3d, t_coord *intersection, double cast_angle)
{
	double	distance;

	distance = cos_degrees(cast_angle) * (c3d->position->x - intersection->x)
		- sin_degrees(cast_angle) * (c3d->position->y - intersection->y);
	distance = absolute_doub(distance, 0);
	return (distance);
}

double	distance_proj(void)
{
	double	distance;

	distance = ((double)PROJ_X / 2) / tan_degrees ((double)FOV / 2);
	return (distance);
}

double	angle_between_rays(void)
{
	double	angle;

	angle = (double)FOV / (double)PROJ_X;
	return (angle);
}
