/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/02/06 10:57:59 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	encode_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
	return (red << 16 | green << 8 | blue);
}

int	color_screen(t_win *window, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HGT)
	{
		while (x < WID)
		{
			mlx_pixel_put(window->mlx_conn, window->mlx_win, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	zoom(int x, int y, t_win *window, double fact)
{
	double	dif_x;
	double	dif_y;

	if (1.5 * (long)x < window->zoom.base_x)
		move_view(x, y, window, LEFT);
	if (0.7 * (long)x > window->zoom.base_x)
		move_view(x, y, window, RIGHT);
	if (1.5 * (long)y < window->zoom.base_y)
		move_view(x, y, window, UP);
	if (0.7 * (long)y > window->zoom.base_y)
		move_view(x, y, window, DOWN);
	dif_x = (window->zoom.x_max - window->zoom.x_min)
		- ((window->zoom.x_max - window->zoom.x_min) * fact);
	dif_y = (window->zoom.y_max - window->zoom.y_min)
		- ((window->zoom.y_max - window->zoom.y_min) * fact);
	window->zoom.x_max = window->zoom.x_max + dif_x;
	window->zoom.x_min = window->zoom.x_min - dif_x;
	window->zoom.y_max = window->zoom.y_max + dif_y;
	window->zoom.y_min = window->zoom.y_min - dif_y;
	return (0);
}

int	move_view(int x, int y, t_win *window, int direction)
{
	double	dif_x;
	double	dif_y;

	(void) x;
	(void) y;
	dif_x = 0;
	dif_y = 0;
	if (direction == LEFT)
		dif_x = (window->zoom.x_max - window->zoom.x_min) * 0.2;
	else if (direction == RIGHT)
		dif_x = - (window->zoom.x_max - window->zoom.x_min) * 0.2;
	else if (direction == UP)
		dif_y = - (window->zoom.y_max - window->zoom.y_min) * 0.2;
	else if (direction == DOWN)
		dif_y = (window->zoom.y_max - window->zoom.y_min) * 0.2;
	window->zoom.y_min = window->zoom.y_min - dif_y;
	window->zoom.y_max = window->zoom.y_max - dif_y;
	window->zoom.x_min = window->zoom.x_min - dif_x;
	window->zoom.x_max = window->zoom.x_max - dif_x;
	return (0);
}
