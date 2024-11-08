/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/24 12:35:51 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	minimap(t_cub *c3d, int x, int y)
{
	double	x_factor;
	double	y_factor;

	y_factor = (double) c3d->map->size_y / (double) MM_Y_SIZE;
	x_factor = (double) c3d->map->size_x / (double) MM_X_SIZE;
	if (c3d->map->coord[(int)floor((double) x * x_factor)]
		[(int)floor((double) y * y_factor)] == 0)
		return (encode_rgb(0, 0, 0));
	else if (c3d->map->coord[(int)floor((double) x * x_factor)]
		[(int)floor((double) y * y_factor)] == 1)
		return (encode_rgb(200, 200, 200));
	else if (c3d->map->coord[(int)floor((double) x * x_factor)]
		[(int)floor((double) y * y_factor)] == DOOR_CLOSED)
		return (encode_rgb(100, 100, 100));
	else if (c3d->map->coord[(int)floor((double) x * x_factor)]
		[(int)floor((double) y * y_factor)] == DOOR_OPEN)
		return (encode_rgb(50, 50, 50));
	else if (c3d->map->coord[(int)floor((double) x * x_factor)]
		[(int)floor((double) y * y_factor)] == DOOR_HALF)
		return (encode_rgb(100, 100, 50));
	else
		return (0);
}

void	add_cursor(t_cub *c3d)
{
	int	x;
	int	y;

	x = (int)(round((double)c3d->position->x / ((double) c3d->map->size_x
					/ (double) MM_X_SIZE)) + MM_X_START);
	y = (int)(round((double)c3d->position->y / ((double) c3d->map->size_y
					/ (double) MM_Y_SIZE)) + MM_Y_START);
	pixel_to_img(&(c3d->win->img), x, y, encode_rgb(240, 0, 0));
	pixel_to_img(&(c3d->win->img), x + 1, y, encode_rgb(240, 0, 0));
	pixel_to_img(&(c3d->win->img), x - 1, y, encode_rgb(240, 0, 0));
	pixel_to_img(&(c3d->win->img), x, y + 1, encode_rgb(240, 0, 0));
	pixel_to_img(&(c3d->win->img), x, y - 1, encode_rgb(240, 0, 0));
	x = (int)(round((c3d->position->x + cos_degrees(c3d->direction) * STEP * 2)
				/ ((double) c3d->map->size_x / (double) MM_X_SIZE))
			+ MM_X_START);
	y = (int)(round((c3d->position->y - sin_degrees(c3d->direction) * STEP * 2)
				/ ((double) c3d->map->size_y / (double) MM_Y_SIZE))
			+ MM_Y_START);
	pixel_to_img(&(c3d->win->img), x, y, encode_rgb(255, 255, 0));
}

void	write_minimap(t_cub *c3d)
{
	int		x;
	int		y;

	x = MM_X_START;
	while (x < PROJ_X && x < MM_X_START + MM_X_SIZE)
	{
		y = MM_Y_START;
		while (y < PROJ_Y && y < MM_Y_START + MM_Y_SIZE)
		{
			pixel_to_img(&(c3d->win->img), x, y,
				minimap(c3d, x - MM_X_START, y - MM_Y_START));
			y++;
		}
		x++;
	}
	add_cursor(c3d);
}
