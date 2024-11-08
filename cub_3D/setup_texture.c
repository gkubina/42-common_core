/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/25 10:31:34 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_win *window, t_cub *c3d, int face, char *filename)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	(void)c3d;
	window->texture[face].img_ptr
		= mlx_xpm_file_to_image(window->mlx_conn, filename, &x, &y);
	if (window->texture[face].img_ptr == NULL)
		clean_x(c3d);
	c3d->tex[face].hgt = y;
	c3d->tex[face].wid = x;
	window->texture[face].img_pixels_ptr
		= mlx_get_data_addr(window->texture[face].img_ptr,
			&window->texture[face].bits_per_pixel,
			&window->texture[face].line_len,
			&window->texture[face].endian);
}

void	setup_texture(t_win *window, t_cub *c3d, t_element *element)
{
	int	i;

	i = -1;
	while (++i < TEXNB)
		window->texture[i].img_ptr = NULL;
	load_texture(window, c3d, N, element->no_path);
	load_texture(window, c3d, E, element->ea_path);
	load_texture(window, c3d, W, element->we_path);
	load_texture(window, c3d, S, element->so_path);
	if (element->d_path)
		load_texture(window, c3d, DOOR, element->d_path);
}
