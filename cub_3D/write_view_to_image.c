/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_view_to_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/07/01 09:12:39 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_scale(int height, double step)
{
	double	scale;

	if (height > PROJ_Y)
		scale = ((height - PROJ_Y) / 2) * step;
	else
		scale = 0;
	return (scale);
}

int	skycolor(t_cub *c3d)
{
	return (encode_rgb(c3d->sky.r, c3d->sky.g, c3d->sky.b));
}

int	floorcolor(t_cub *c3d)
{
	return (encode_rgb(c3d->floor.r, c3d->floor.g, c3d->floor.b));
}

int	offset_of_tile(t_ray *ray, t_cub *c3d)
{
	double	offset;

	if (ray->face == N || ray->face == S)
		offset = ((int) ray->intersection.x % GRIDSIZE);
	else
		offset = ((int) ray->intersection.y % GRIDSIZE);
	offset = offset * ((double) c3d->tex[ray->tex].wid / (double) GRIDSIZE);
	return ((int)offset);
}

void	write_column(t_cub *c3d, t_ray *ray, int height, int column)
{
	int		i;
	int		offset;
	double	scale;
	double	step;

	step = (double) c3d->tex[ray->tex].hgt / (double)height;
	scale = get_scale(height, step);
	i = -1;
	offset = offset_of_tile(ray, c3d);
	while (++i < ((PROJ_Y - height) / 2) && i < PROJ_Y)
		pixel_to_img(&(c3d->win->img), column, i, skycolor(c3d));
	while (i < (((PROJ_Y - height) / 2) + height) && i < PROJ_Y)
	{
		if (ray->tex == DOOR)
			pixel_to_img(&(c3d->win->img), column, i++,
				pixel_from_img(&(c3d->win->texture[ray->tex]),
					offset, floor(scale)) | c3d->sprite << 13);
		else
			pixel_to_img(&(c3d->win->img), column, i++,
				pixel_from_img(&(c3d->win->texture[ray->tex]),
					offset, floor(scale)));
		scale += step;
	}
	while (i < PROJ_Y)
		pixel_to_img(&(c3d->win->img), column, i++, floorcolor(c3d));
}
