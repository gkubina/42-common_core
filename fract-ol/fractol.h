/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:39:26 by gkubina           #+#    #+#             */
/*   Updated: 2024/02/06 10:57:49 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define SLEEP_TIME			3
# define MALLOC_ERROR		-1
# define WID				800
# define HGT				500
# define SIZE				2
# define WINNAME			"Fractol"
# define COMPL_ADD			1
# define COMPL_SUB			2
# define COMPL_MUL			3
# define COMPL_DIV			4
# define MAX_ITER			100
# define INFINI				3
# define ZOOM_FAC			1.0
# define LEFT				1
# define RIGHT				2
# define UP					3
# define DOWN				4

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_complex
{
	double	r;
	double	i;
}			t_complex;

typedef struct s_zoom
{
	double	base_x;
	double	base_y;
	double	zoom;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}			t_zoom;

typedef struct s_fractal
{
	int			type;
	t_complex	julia_c;
	int			colorshift;
}			t_fractal;

typedef struct s_win
{
	void		*mlx_conn;
	void		*mlx_win;
	t_zoom		zoom;
	t_img		img;
	t_fractal	fractal;
}			t_win;

int			config_x(t_win *window);
int			clean_x(t_win *window);
int			handle_input_x(int keysym, t_win *window);
int			handle_mouse_button(int button, int x, int y, t_win *window);
int			std_action(t_win *window);

int			encode_rgb(unsigned char red, unsigned char green,
				unsigned char blue);
int			color_screen(t_win *window, int color);
void		pixel_to_img(t_img *img, int x, int y, int color);

t_complex	init_complex(void);
t_complex	calc_complex(t_complex comp_1, t_complex comp_2, int operator);

t_complex	get_complex(int x, int y, t_zoom info);
int			write_fractal(t_win *window);
t_zoom		init_zoom(void);
int			init_fractal(t_fractal *fractal, int argc, char **argv);

int			fractal(t_win *window, t_complex complex);

int			mandelbrot(t_complex complex);
int			julia(t_complex complex, t_complex c);
int			burning_ship(t_complex complex);

double		ft_abs(double a, double b);
double		ft_atod(const char *nptr);

int			zoom(int x, int y, t_win *window, double fact);
int			move_view(int x, int y, t_win *window, int direction);
t_complex	next_mandel(t_win *window);

#endif
