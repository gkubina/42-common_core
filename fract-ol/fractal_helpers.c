/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/02/06 10:57:08 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	get_complex(int x, int y, t_zoom info)
{
	t_complex	new;

	new.r = (info.x_min + (x * ((info.x_max - info.x_min) / WID)));
	new.i = ((-1 * info.y_max) + (y * ((info.y_max - info.y_min) / HGT)));
	return (new);
}

t_zoom	init_zoom(void)
{
	t_zoom	new;

	new.base_x = WID / 2;
	new.base_y = HGT / 2;
	new.zoom = 1;
	new.x_min = -SIZE;
	new.x_max = SIZE;
	new.y_min = -SIZE;
	new.y_max = SIZE;
	return (new);
}

int	fractal(t_win *window, t_complex complex)
{
	int	result;

	result = 0;
	if (window->fractal.type == 1)
	{
		result = mandelbrot(complex);
		return (encode_rgb(result * window->fractal.colorshift * 5,
				result * window->fractal.colorshift * 2,
				result * window->fractal.colorshift * 4));
	}
	else if (window->fractal.type == 2)
	{
		result = julia(complex, window->fractal.julia_c);
		return (encode_rgb(result * window->fractal.colorshift * 2,
				result * window->fractal.colorshift,
				result * window->fractal.colorshift * 3));
	}
	else if (window->fractal.type == 3)
	{
		result = burning_ship(complex);
		return (encode_rgb(result * window->fractal.colorshift * 3,
				result * window->fractal.colorshift,
				result * window->fractal.colorshift * 2));
	}
	return (0);
}

int	write_fractal(t_win *window)
{
	int			x;
	int			y;
	t_complex	complex;
	int			color;

	x = 0;
	y = 0;
	while (y < HGT)
	{
		while (x < WID)
		{
			complex = get_complex(x, y, window->zoom);
			color = fractal(window, complex);
			pixel_to_img(&window->img, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(window->mlx_conn, window->mlx_win,
		window->img.img_ptr, 0, 0);
	return (0);
}

void	pixel_to_img(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(img->img_pixels_ptr + offset)) = color;
}
