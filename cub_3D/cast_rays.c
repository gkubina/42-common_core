/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/24 14:49:34 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_face(double cast_angle, int intersection)
{
	if (intersection == HORIZONTAL)
	{
		if (cast_angle < 180)
			return (S);
		else
			return (N);
	}
	else
	{
		if (cast_angle < 90 || cast_angle > 270)
			return (W);
		else
			return (E);
	}
}

t_ray	find_closest_inter(t_cub *c3d, t_coord *position, double cast_angle)
{
	t_coord	intersec_horiz;
	double	horiz_dist;
	double	vert_dist;
	t_ray	ray;

	(void) position;
	horiz_dist = __DBL_MAX__;
	vert_dist = __DBL_MAX__;
	cast_angle = angle_360(cast_angle);
	intersec_horiz = find_horiz_inter(c3d, c3d->position, cast_angle);
	ray.intersection = find_vert_inter(c3d, c3d->position, cast_angle);
	if (cast_angle != 0 && cast_angle != 180)
		horiz_dist = distance_points(c3d, &intersec_horiz, cast_angle);
	if (cast_angle != 90 && cast_angle != 270)
		vert_dist = distance_points(c3d, &(ray.intersection), cast_angle);
	ray.face = get_face(cast_angle, VERTICAL);
	if (absolute_doub(horiz_dist, 0) < absolute_doub(vert_dist, 0))
	{
		ray.distance = absolute_doub(horiz_dist, 0);
		ray.face = get_face(cast_angle, HORIZONTAL);
		ray.intersection = intersec_horiz;
	}
	else
		ray.distance = absolute_doub(vert_dist, 0);
	return (ray);
}

double	fishbowl_correction(int column)
{
	double	angle;
	double	fishbowl;

	if (column < PROJ_X / 2)
		angle = (double)(FOV / 2) - (column * angle_between_rays());
	else
		angle = (double)(column - (PROJ_X / 2))
			*angle_between_rays();
	fishbowl = cos_degrees(angle);
	return (fishbowl);
}

int	projected_wallslice_height(int column, t_ray *ray)
{
	double	height;

	height = (GRIDSIZE / (ray->distance
				* fishbowl_correction(column))) * distance_proj();
	return ((int)round(height));
}

void	cast_rays(t_cub *c3d)
{
	int		column;
	t_ray	ray;
	double	startangle;
	int		height;

	startangle = angle_360(c3d->direction + (double)(FOV / 2));
	column = -1;
	while (++column < PROJ_X)
	{
		ray = find_closest_inter(c3d, c3d->position,
				startangle - (double)column * angle_between_rays());
		height = projected_wallslice_height(column, &ray);
		if (is_door(&ray, c3d) > 0)
			ray.tex = DOOR;
		else
			ray.tex = ray.face;
		write_column(c3d, &ray, height, column);
	}
	write_minimap(c3d);
	mlx_put_image_to_window(c3d->win->mlx_conn, c3d->win->mlx_win,
		c3d->win->img.img_ptr, 0, 0);
}
