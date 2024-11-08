/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/02/06 10:58:10 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	config_x(t_win *window)
{
	window->mlx_conn = mlx_init();
	if (window->mlx_conn == NULL)
		return (MALLOC_ERROR);
	window->mlx_win = mlx_new_window(window->mlx_conn, WID, HGT, WINNAME);
	if (window->mlx_win == NULL)
	{
		mlx_destroy_display(window->mlx_conn);
		free(window->mlx_conn);
		return (MALLOC_ERROR);
	}
	window->img.img_ptr = mlx_new_image(window->mlx_conn, WID, HGT);
	window->img.img_pixels_ptr = mlx_get_data_addr(window->img.img_ptr,
			&window->img.bits_per_pixel, &window->img.line_len,
			&window->img.endian);
	write_fractal(window);
	mlx_key_hook(window->mlx_win, handle_input_x, window);
	mlx_hook(window->mlx_win, ButtonPress, ButtonPressMask,
		&handle_mouse_button, window);
	mlx_hook(window->mlx_win, DestroyNotify, StructureNotifyMask,
		&clean_x, window);
	mlx_loop_hook(window->mlx_conn, std_action, window);
	mlx_loop(window->mlx_conn);
	return (0);
}

int	clean_x(t_win *window)
{
	if (window->img.img_ptr != NULL)
	{
		mlx_destroy_image(window->mlx_conn, window->img.img_ptr);
	}
	if (window->mlx_conn != NULL && window->mlx_win != NULL)
		mlx_destroy_window(window->mlx_conn, window->mlx_win);
	if (window->mlx_conn != NULL)
	{
		mlx_destroy_display(window->mlx_conn);
		free(window->mlx_conn);
	}
	exit(1);
	return (0);
}

int	std_action(t_win *window)
{
	window->fractal.colorshift++;
	write_fractal(window);
	window->fractal.colorshift = window->fractal.colorshift % 152;
	return (0);
}

int	handle_input_x(int keysym, t_win *window)
{
	if (keysym == XK_Escape)
		clean_x(window);
	if (keysym == XK_Left)
		move_view(0, 0, window, LEFT);
	if (keysym == XK_Right)
		move_view(0, 0, window, RIGHT);
	if (keysym == XK_Up)
		move_view(0, 0, window, UP);
	if (keysym == XK_Down)
		move_view(0, 0, window, DOWN);
	if (keysym == XK_Home)
		window->zoom = init_zoom();
	return (0);
}

int	handle_mouse_button(int button, int x, int y, t_win *window)
{
	(void) window;
	if (button == 4)
	{
		zoom(x, y, window, 1.2);
	}
	if (button == 5)
	{
		zoom(x, y, window, 0.8);
	}
	return (0);
}
