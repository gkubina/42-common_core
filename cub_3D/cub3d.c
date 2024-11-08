/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/29 10:45:04 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	clean_x(t_cub *c3d)
{
	t_win	*window;
	int		i;

	i = -1;
	window = c3d->win;
	while (++i < TEXNB)
	{
		if (window->texture[i].img_ptr != NULL)
			mlx_destroy_image(window->mlx_conn, window->texture[i].img_ptr);
	}
	if (window->img.img_ptr != NULL)
		mlx_destroy_image(window->mlx_conn, window->img.img_ptr);
	if (window->mlx_conn != NULL && window->mlx_win != NULL)
		mlx_destroy_window(window->mlx_conn, window->mlx_win);
	if (window->mlx_conn != NULL)
	{
		mlx_destroy_display(window->mlx_conn);
		free(window->mlx_conn);
	}
	free_allocs(c3d);
	exit(1);
	return (0);
}

void	free_allocs(t_cub *c3d)
{
	int	x;

	x = -1;
	if (c3d->map && c3d->map->coord)
	{
		while (++x < c3d->map->size_x && c3d->map->coord[x])
			free(c3d->map->coord[x]);
	}
	x = -1;
	if (c3d->map && c3d->map->coord)
		free(c3d->map->coord);
	if (c3d->position)
		free(c3d->position);
	if (c3d->map)
		free(c3d->map);
	ft_free_element(c3d->element);
}

static void	set_colors(t_cub *c3d, t_element *element)
{
	c3d->floor.r = element->floor->r;
	c3d->floor.b = element->floor->b;
	c3d->floor.g = element->floor->g;
	c3d->sky.r = element->ceiling->r;
	c3d->sky.b = element->ceiling->b;
	c3d->sky.g = element->ceiling->g;
}

void	fatal_error(t_cub *c3d)
{
	free_allocs(c3d);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_win				window;
	t_cub				c3d;
	static t_element	element;

	if (argc < 2)
	{
		printf("Error\nYou need an argument .cub\n");
		return (1);
	}
	if (ft_parsing(argv[1], &element) || ft_lst_to_map(&element))
	{
		ft_free_element(&element);
		return (1);
	}
	if (element.bonus)
		check_doors_position(&element);
	c3d.element = &element;
	fill_map(&c3d, &element);
	set_colors(&c3d, &element);
	c3d.sprite = 0;
	c3d.mouse_mov = 0;
	if (config_x(&window, &c3d, &element) != MALLOC_ERROR)
		sleep(1);
	free_allocs(&c3d);
	return (0);
}
