/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/24 12:32:15 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	close_door(t_cub *c3d, double p_x, double p_y)
{
	int	x;
	int	y;
	int	pos_x;
	int	pos_y;

	pos_x = ((int)p_x / GRIDSIZE) * GRIDSIZE;
	pos_y = ((int)p_y / GRIDSIZE) * GRIDSIZE;
	y = 0;
	while (pos_y + y < pos_y + GRIDSIZE)
	{
		x = 0;
		while (pos_x + x < pos_x + GRIDSIZE)
		{
			c3d->map->coord[pos_x + x][pos_y + y] = DOOR_CLOSED;
			x++;
		}
		y++;
	}
}

static void	open_door(t_cub *c3d, double p_x, double p_y)
{
	int	x;
	int	y;
	int	pos_x;
	int	pos_y;

	pos_x = ((int)p_x / GRIDSIZE) * GRIDSIZE;
	pos_y = ((int)p_y / GRIDSIZE) * GRIDSIZE;
	y = 0;
	while (pos_y + y < pos_y + GRIDSIZE)
	{
		x = 0;
		while (pos_x + x < pos_x + GRIDSIZE)
		{
			c3d->map->coord[pos_x + x][pos_y + y] = DOOR_OPEN;
			x++;
		}
		y++;
	}
}
/*
void	change_block(t_cub *c3d, double p_x, double p_y,
		int type)
{
	int	x;
	int	y;
	int	pos_x;
	int	pos_y;

	pos_x = ((int)p_x / GRIDSIZE) * GRIDSIZE;
	pos_y = ((int)p_y / GRIDSIZE) * GRIDSIZE;
	y = 0;
	while (pos_y + y < pos_y + GRIDSIZE)
	{
		x = 0;
		while (pos_x + x < pos_x + GRIDSIZE)
		{
			c3d->map->coord[pos_x + x][pos_y + y] = type;
			x++;
		}
		y++;
	}
}
*/

/*
int	is_door(t_ray *ray, t_cub *c3d)
{
	if (ray->intersection.x > 0 && ray->intersection.x < c3d->map->size_x
		&& ray->intersection.y > 0
		&& ray->intersection.y < c3d->map->size_y
		&& (c3d->map->coord
		[(int)floor(ray->intersection.x)]
		[(int)floor(ray->intersection.y)] == DOOR_CLOSED ||
		c3d->map->coord
		[(int)floor(ray->intersection.x)]
		[(int)floor(ray->intersection.y)] == DOOR_HALF))
		return (1);
	else if (
		(c3d->map->coord
		[(int)floor(ray->intersection.x) + 1]
		[(int)floor(ray->intersection.y) + 1] == DOOR_OPEN ||
		c3d->map->coord
		[(int)floor(ray->intersection.x) + 1]
		[(int)floor(ray->intersection.y) + 1] == DOOR_HALF)
		||
		(c3d->map->coord
		[(int)floor(ray->intersection.x) - 1]
		[(int)floor(ray->intersection.y) + 1] == DOOR_OPEN ||
		c3d->map->coord
		[(int)floor(ray->intersection.x) - 1]
		[(int)floor(ray->intersection.y) + 1] == DOOR_HALF)
		||
		(c3d->map->coord
		[(int)floor(ray->intersection.x) + 1]
		[(int)floor(ray->intersection.y) - 1] == DOOR_OPEN ||
		c3d->map->coord
		[(int)floor(ray->intersection.x) + 1]
		[(int)floor(ray->intersection.y) - 1] == DOOR_HALF)
		||
		(c3d->map->coord
		[(int)floor(ray->intersection.x) - 1]
		[(int)floor(ray->intersection.y) - 1] == DOOR_OPEN ||
		c3d->map->coord
		[(int)floor(ray->intersection.x) - 1]
		[(int)floor(ray->intersection.y) - 1] == DOOR_HALF))
		return (1);
	// {
	// 	return (c3d->map->coord
	// 		[(int)floor(ray->intersection.x)]
	// 		[(int)floor(ray->intersection.y)] - 1);
	// }
	return (0);
}
*/

int	is_door(t_ray *ray, t_cub *c3d)
{
	int	x;
	int	y;

	x = (int)floor(ray->intersection.x);
	y = (int)floor(ray->intersection.y);
	if (x > 0 && x < c3d->map->size_x && y > 0 && y < c3d->map->size_y
		&& (c3d->map->coord[x][y] == DOOR_CLOSED
		|| c3d->map->coord[x][y] == DOOR_HALF
		|| c3d->map->coord[x + 1][y + 1] == DOOR_OPEN
		|| c3d->map->coord[x + 1][y + 1] == DOOR_HALF
		|| c3d->map->coord[x - 1][y + 1] == DOOR_OPEN
		|| c3d->map->coord[x - 1][y + 1] == DOOR_HALF
		|| c3d->map->coord[x + 1][y - 1] == DOOR_OPEN
		|| c3d->map->coord[x + 1][y - 1] == DOOR_HALF
		|| c3d->map->coord[x - 1][y - 1] == DOOR_OPEN
		|| c3d->map->coord[x - 1][y - 1] == DOOR_HALF))
		return (1);
	return (0);
}

void	try_to_open_or_close_door(t_cub *c3d)
{
	double	x;
	double	y;

	c3d->direction = angle_360(c3d->direction);
	x = c3d->position->x + cos_degrees(c3d->direction) * GRIDSIZE;
	y = c3d->position->y - sin_degrees(c3d->direction) * GRIDSIZE;
	if (!change_door_status(c3d, x, y))
	{
		x = x + cos_degrees(c3d->direction) * GRIDSIZE;
		y = y - sin_degrees(c3d->direction) * GRIDSIZE;
		change_door_status(c3d, x, y);
	}
}

int	change_door_status(t_cub *c3d, double x, double y)
{
	if (x > 0 && x < c3d->map->size_x
		&& y > 0
		&& y < c3d->map->size_y
		&& c3d->map->coord
		[(int)floor(x)]
		[(int)floor(y)] == DOOR_CLOSED)
	{
		open_door(c3d, x, y);
		c3d->sprite = 1;
		return (1);
	}
	else if (x > 0 && x < c3d->map->size_x
		&& y > 0
		&& y < c3d->map->size_y
		&& (c3d->map->coord
			[(int)floor(x)]
			[(int)floor(y)] == DOOR_OPEN || c3d->map->coord
			[(int)floor(x)]
			[(int)floor(y)] == DOOR_HALF))
	{
		close_door(c3d, x, y);
		c3d->sprite = 1;
		return (1);
	}
	return (0);
}
