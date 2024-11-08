/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleliev <daleliev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:39:26 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/29 09:58:55 by daleliev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

# define MALLOC_ERROR		-1
# define WID				PROJ_X
# define HGT				PROJ_Y
# define WINNAME			"cub3D"

# define SKY_R 10
# define SKY_G 10
# define SKY_B 150

# define FLOOR_R 60
# define FLOOR_G 50
# define FLOOR_B 10

# define LEFT				1
# define RIGHT				2
# define UP					3
# define DOWN				4

# define TEXNB 5

# define N				0
# define E				1
# define S				2
# define W				3
# define DOOR			4 

# define LEFT_KEY				XK_a
# define RIGHT_KEY				XK_d
# define UP_KEY					XK_w
# define DOWN_KEY				XK_s
# define OPEN_KEY				XK_o
# define MOUSE_KEY				XK_m

# define MY_PI 3.14159265358979323846

// CUB3D definitions

# define PROJ_X 1536
# define PROJ_Y 1200
# define GRIDSIZE 128
# define FOV 60

# define OFFSET 0.0001
# define STEP 8
# define TURNSTEP 10
# define MAXTEST 25

# define DOOR_CLOSED 2
# define DOOR_OPEN -1
# define DOOR_HALF 3

# define NORTH 90
# define EAST 0
# define SOUTH 270
# define WEST 180

# define HORIZONTAL 0
# define VERTICAL 90

# define MM_X_SIZE 400
# define MM_Y_SIZE 400
# define MM_X_START 10
# define MM_Y_START 10

typedef struct s_values
{
	int	r;
	int	g;
	int	b;
}	t_values;

typedef struct s_listb
{
	char			*str;
	char			letter;
	int				nb_letter;
	int				nb_door;
	int				len;
	struct s_listb	*next;
}	t_listb;

typedef struct s_element
{
	char		*no_path;
	int			fd_no;
	char		*so_path;
	int			fd_so;
	char		*we_path;
	int			fd_we;
	char		*ea_path;
	int			fd_ea;
	char		*d_path;
	int			fd_d;
	t_values	*floor;
	int			is_floor;
	t_values	*ceiling;
	int			is_ceiling;
	int			bonus;
	char		**map;
	int			error;
	t_listb		*lst;
}	t_element;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_win
{
	void		*mlx_conn;
	void		*mlx_win;
	t_img		img;
	t_img		texture[TEXNB];
}			t_win;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}			t_color;

typedef struct s_texture
{
	int			hgt;
	int			wid;
}			t_texture;

typedef struct s_coord
{
	double		x;
	double		y;
}			t_coord;

typedef struct s_map
{
	int	**coord;
	int	size_x;
	int	size_y;
}			t_map;

typedef struct s_ray
{
	double	distance;
	t_coord	intersection;
	int		face;
	int		tex;
}			t_ray;

typedef struct s_cub
{
	int			mouse_mov;
	int			sprite;
	t_color		sky;
	t_color		floor;
	t_texture	tex[TEXNB];
	t_map		*map;
	t_coord		*position;
	double		direction;
	t_win		*win;
	t_element	*element;
}			t_cub;

// X maangement
int		config_x(t_win *window, t_cub *c3d, t_element *element);
int		handle_input_x(int keysym, t_cub *c3d);
int		mouse_btn(int button, int x, int y, t_cub *c3d);
// int		std_action(t_win *window);
void	setup_texture(t_win *window, t_cub *c3d, t_element *element);
int		mouse_mv(int x, int y, t_cub *c3d);
//int			handle_input_x(int keysym, t_win *window);

// Free and Clean
void	free_allocs(t_cub *c3d);
int		clean_x(t_cub *c3d);
void	fatal_error(t_cub *c3d);

// Image helpers
int		encode_rgb(unsigned char red, unsigned char green,
			unsigned char blue);
void	pixel_to_img(t_img *img, int x, int y, int color);
int		pixel_from_img(t_img *img, int x, int y);

// testmap setup
void	fill_map(t_cub *c3d, t_element *element);
void	print_testmap(t_cub *c3d);
void	setup_map(t_cub *c3d, int size_x, int size_y, t_element *element);
void	setup_block(t_cub *c3d, int pos_x, int pos_y, char type);
void	alloc_map(t_cub *c3d, int size_x, int size_y);

// Math helpers
int		absolute_int(int a, int b);
double	absolute_doub(double a, double b);
double	tan_degrees(double x);
double	cos_degrees(double x);
double	sin_degrees(double x);

//Ray cast helpers
double	angle_360(double angle);
// double	distance_points(t_coord *a, t_coord *b, double cast_angle);
double	distance_points(t_cub *c3d, t_coord *b, double cast_angle);
double	distance_proj(void);
double	angle_between_rays(void);

// Raycast: Find intersections
t_coord	find_horiz_inter(t_cub *c3d, t_coord *position, double cast_angle);
t_coord	find_vert_inter(t_cub *c3d, t_coord *position, double cast_angle);
void	cast_rays(t_cub *c3d);

// Write view to image
void	write_column(t_cub *c3d, t_ray *ray, int height, int column);

// Actions
void	move(t_cub *c3d, int movetype);

// Doors
//void	change_block(t_cub *c3d, double p_x, double p_y,
//			int type);
int		is_door(t_ray *ray, t_cub *c3d);
int		change_door_status(t_cub *c3d, double x, double y);
void	try_to_open_or_close_door(t_cub *c3d);

// write minimap
void	write_minimap(t_cub *c3d);

// Setup map helpers
int		x_size_map(t_element *element);
int		y_size_map(t_element *element);
int		ft_find_alpha(char *str);

// Parsing
int		ft_is_cub(char *doc);
int		ft_isspace_mod(char c);
int		ft_parsing(char *doc, t_element *element);
int		line_has_smthg(char *line);
char	*ft_start_lst(char *line, t_element *element, int fd);
void	ft_map_to_lst(char *line, t_element *element);
int		ft_lst_to_map(t_element *element);
void	ft_free_element(t_element *element);
char	*dup_with_a_size(char *str, int size);
int		move_to_next_nb(char *str, int i, t_element *element);
int		ft_atoi_color(char *str, int i, t_element *element, int *color);
void	*ft_check_cl(char *str, t_element *element, t_values *color, int *ok);
void	ft_check_if_you_can_add_color(char *str, int *i, int *nb, int *coma);
void	*ft_add_color(char *str, t_values *color, t_element *el, int *ok);
int		ft_check_each_str(char *str, t_element *element);
int		ft_check_lst(t_listb *lst, t_element *element);
void	ft_fill_map(t_element *element, int len);
void	for_last_line(char **map, int i, int j, t_element *el);
void	check_for_conditions(char **map, int j, int i, t_element *element);
void	printf_error(void);
void	check_doors_position(t_element *el);
void	err(char *str, t_element *element);

#endif
