/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/25 10:34:58 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	alloc_map(t_cub *c3d, int size_x, int size_y)
{
	int	x;

	c3d->position = ft_calloc(1, sizeof(t_coord));
	if (c3d->position == NULL)
		fatal_error(c3d);
	c3d->map = ft_calloc(1, sizeof(t_map));
	if (c3d->map == NULL)
		fatal_error(c3d);
	c3d->map->coord = ft_calloc(size_x * GRIDSIZE, sizeof(int *));
	if (c3d->map->coord == NULL)
		fatal_error(c3d);
	c3d->map->size_x = size_x * GRIDSIZE;
	x = 0;
	while (x < size_x * GRIDSIZE)
	{
		c3d->map->coord[x] = ft_calloc(size_y * GRIDSIZE, sizeof(int));
		if (c3d->map->coord[x] == NULL)
			fatal_error(c3d);
		x++;
	}
	c3d->map->size_y = size_y * GRIDSIZE;
}

void	setup_block(t_cub *c3d, int pos_x, int pos_y,
		char type)
{
	int	x;
	int	y;

	pos_x = GRIDSIZE * pos_x;
	pos_y = GRIDSIZE * pos_y;
	y = 0;
	if (ft_isalpha(type) || type == ' ')
		type = '0';
	while (pos_y + y < pos_y + GRIDSIZE)
	{
		x = 0;
		while (pos_x + x < pos_x + GRIDSIZE)
		{
			c3d->map->coord[pos_x + x][pos_y + y] = (int)(type - '0');
			x++;
		}
		y++;
	}
}

void	set_start_position(t_element *element, t_cub *c3d)
{
	int			y;
	t_listb		*list;

	y = 0;
	list = element->lst;
	while (list)
	{
		if (list->letter)
		{
			if (list->letter == 'N')
				c3d->direction = NORTH;
			else if (list->letter == 'E')
				c3d->direction = EAST;
			else if (list->letter == 'S')
				c3d->direction = SOUTH;
			else
				c3d->direction = WEST;
			c3d->position->x = (double)(ft_find_alpha(list->str) * GRIDSIZE
					+ GRIDSIZE / 2);
			c3d->position->y = (double)(y * GRIDSIZE + GRIDSIZE / 2);
		}
		y++;
		list = list->next;
	}
}

void	setup_map(t_cub *c3d, int size_x, int size_y, t_element *element)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	while (y < size_y)
	{
		x = 0;
		line = element->map[y];
		while (x < size_x && line && (size_t)x < ft_strlen(line))
		{
			setup_block(c3d, x, y, line[x]);
			x++;
		}
		y++;
	}
}

void	fill_map(t_cub *c3d, t_element *element)
{
	int	x;
	int	y;

	x = x_size_map(element);
	y = y_size_map(element);
	alloc_map(c3d, x, y);
	setup_map(c3d, x, y, element);
	set_start_position(element, c3d);
}
