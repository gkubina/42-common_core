NAME = cub3D

HEADER = cub3d.h

MLXDIR = ./minilibx-linux

MLX_LIB = $(MLXDIR)/libmlx_Linux.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -g -O1

LFTDIR = ./libft

LFTA = $(LFTDIR)/libft.a

SRC = \
	cub3d.c \
	setup_map.c \
	setup_map_helpers.c \
	manage_x.c \
	image_helpers.c \
	math_helpers.c \
	ray_cast_helpers.c \
	ray_calculations_horiz.c \
	ray_calculations_vert.c \
	cast_rays.c \
	write_view_to_image.c \
	actions.c \
	setup_texture.c \
	doors.c \
	minimap.c \
    	parsing.c\
    	parsing_utils.c\
    	maptolst.c\
    	lst_to_map.c\
    	free_element.c\
	parsing_utils2.c\
	lst_to_map_utils.c\
	checkdoorsposition.c\

SRC_BONUS = \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(LFTA) $(OBJ) $(MLX_LIB)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) -L$(LFTDIR) -lft -L$(MLXDIR) -lmlx_Linux -I$(MLXDIR) -L/usr/lib -lXext -lX11 -lm #-lz

$(LFTA) :
	make -C $(LFTDIR)

$(MLX_LIB) :
	make -C $(MLXDIR)

%.o: %.c $(MLX_LIB) $(HEADER)
	$(CC) $(FLAGS) -I$(MLXDIR) -I/usr/include -c $< -o $@

clean :
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C $(LFTDIR) clean
	make -C $(MLXDIR) clean

fclean : clean
	rm -f $(NAME)
	rm -f $(MLX_LIB)
	make -C $(LFTDIR) fclean


re : fclean all

bonus : all

.PHONY: all clean fclean re
