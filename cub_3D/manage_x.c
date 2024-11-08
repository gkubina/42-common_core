/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:43 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/25 11:18:46 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	std_action(t_cub *c3d)
{
	static int	colorchange;

	if (c3d->sprite != 0)
	{
		colorchange = colorchange + 5;
		colorchange = colorchange % 75;
	}
	c3d->sprite = colorchange;
	usleep(16666);
	cast_rays(c3d);
	return (0);
}

int	config_x(t_win *window, t_cub *c3d, t_element *element)
{
	c3d->win = window;
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
	setup_texture(window, c3d, element);
	mlx_hook(window->mlx_win, ButtonPress, ButtonPressMask, &mouse_btn, c3d);
	mlx_hook(window->mlx_win, MotionNotify, PointerMotionMask, &mouse_mv, c3d);
	mlx_hook(window->mlx_win, KeyPress, KeyPressMask, handle_input_x, c3d);
	mlx_hook(window->mlx_win, DestroyNotify, StructureNotifyMask,
		&clean_x, c3d);
	mlx_loop_hook(window->mlx_conn, std_action, c3d);
	mlx_loop(window->mlx_conn);
	return (0);
}

int	handle_input_x(int keysym, t_cub *c3d)
{
	if (keysym == XK_Escape)
		clean_x(c3d);
	if (keysym == XK_Left)
		c3d->direction += TURNSTEP;
	if (keysym == XK_Right)
		c3d->direction -= TURNSTEP;
	if (keysym == UP_KEY || keysym == XK_Up)
		move(c3d, UP);
	if (keysym == LEFT_KEY)
		move(c3d, LEFT);
	if (keysym == DOWN_KEY || keysym == XK_Down)
		move(c3d, DOWN);
	if (keysym == RIGHT_KEY)
		move(c3d, RIGHT);
	if (keysym == OPEN_KEY)
		try_to_open_or_close_door(c3d);
	if (keysym == MOUSE_KEY)
	{
		if (c3d->mouse_mov == 0)
			c3d->mouse_mov = 1;
		else
			c3d->mouse_mov = 0;
	}
	return (0);
}

int	mouse_btn(int button, int x, int y, t_cub *c3d)
{
	(void) y;
	if (button == 1)
	{
		if (x < (PROJ_X / 2))
			c3d->direction += TURNSTEP;
		else if (x > (PROJ_X / 2))
			c3d->direction -= TURNSTEP;
	}
	return (0);
}

int	mouse_mv(int x, int y, t_cub *c3d)
{
	static int	old_x;
	static int	count;

	(void) y;
	if (!c3d->mouse_mov)
		return (1);
	if (count == 25)
		count = 0;
	else
		count++;
	if (count != 1)
		return (0);
	if (x - old_x < 0)
		c3d->direction += TURNSTEP;
	else if (x - old_x > 0)
		c3d->direction -= TURNSTEP;
	old_x = PROJ_X / 2;
	mlx_mouse_move(c3d->win->mlx_conn,
		c3d->win->mlx_win, PROJ_X / 2, PROJ_Y / 2);
	return (0);
}
