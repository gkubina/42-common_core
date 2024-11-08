/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/24 11:59:32 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_position(t_cub *c3d, double next_x, double next_y)
{
	if (next_x > 0
		&& next_x < c3d->map->size_x
		&& next_y > 0
		&& next_y < c3d->map->size_y
		&& (c3d->map->coord
			[(int)floor(next_x)]
			[(int)floor(next_y)] < 1 || c3d->map->coord
			[(int)floor(next_x)]
			[(int)floor(next_y)] == DOOR_HALF))
		return (1);
	return (0);
}

int	check_move(t_cub *c3d, int movetype, double angle)
{
	double	next_x;
	double	next_y;

	angle = angle_360(angle);
	if (movetype == LEFT)
	{
		next_x = c3d->position->x - sin_degrees(angle) * (STEP / 2);
		next_y = c3d->position->y - cos_degrees(angle) * (STEP / 2);
	}
	else if (movetype == RIGHT)
	{
		next_x = c3d->position->x + sin_degrees(angle) * (STEP / 2);
		next_y = c3d->position->y + cos_degrees(angle) * (STEP / 2);
	}
	else if (movetype == UP)
	{
		next_x = c3d->position->x + cos_degrees(angle) * (STEP / 2);
		next_y = c3d->position->y - sin_degrees(angle) * (STEP / 2);
	}
	else
	{
		next_x = c3d->position->x - cos_degrees(angle) * (STEP / 2);
		next_y = c3d->position->y + sin_degrees(angle) * (STEP / 2);
	}
	return (check_position(c3d, next_x, next_y));
}

static void	set_next_position(t_cub *c3d, double next_x, double next_y,
	int movetype)
{
	if (next_x > 0
		&& next_x < c3d->map->size_x
		&& next_y > 0
		&& next_y < c3d->map->size_y
		&& (c3d->map->coord
			[(int)floor(next_x)]
			[(int)floor(next_y)] < 1 || c3d->map->coord
			[(int)floor(next_x)]
			[(int)floor(next_y)] == DOOR_HALF))
	{
		if (check_move(c3d, movetype, (double)((int)c3d->direction / 90) *90)
			&& check_move(c3d, movetype,
				(double)(((int)c3d->direction / 90) + 1) *90))
		{
			c3d->position->x = next_x;
			c3d->position->y = next_y;
		}
	}
}

void	move(t_cub *c3d, int movetype)
{
	double	next_x;
	double	next_y;

	if (movetype == LEFT)
	{
		next_x = c3d->position->x - sin_degrees(c3d->direction) * STEP;
		next_y = c3d->position->y - cos_degrees(c3d->direction) * STEP;
	}
	else if (movetype == RIGHT)
	{
		next_x = c3d->position->x + sin_degrees(c3d->direction) * STEP;
		next_y = c3d->position->y + cos_degrees(c3d->direction) * STEP;
	}
	else if (movetype == UP)
	{
		next_x = c3d->position->x + cos_degrees(c3d->direction) * STEP;
		next_y = c3d->position->y - sin_degrees(c3d->direction) * STEP;
	}
	else
	{
		next_x = c3d->position->x - cos_degrees(c3d->direction) * STEP;
		next_y = c3d->position->y + sin_degrees(c3d->direction) * STEP;
	}
	set_next_position(c3d, next_x, next_y, movetype);
}
