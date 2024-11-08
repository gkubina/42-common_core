NAME = fractol

HEADER = fractol.h

MLXDIR = ./minilibx-linux

MLX_LIB = $(MLXDIR)/libmlx_Linux.a

CC = gcc 

FLAGS = -Wall -Wextra -Werror 

LFTDIR = ./libft

LFTA = $(LFTDIR)/libft.a

SRC = \
	fractol.c \
	manage_x.c \
	image_helpers.c \
	math_helpers.c \
	fractal_helpers.c \
	fractals.c \
	ft_atod.c

SRC_BONUS = \
	
OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(LFTA) $(OBJ) $(MLX_LIB)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) -L$(LFTDIR) -lft -L$(MLXDIR) -lmlx_Linux -I$(MLXDIR) -L/usr/lib -lXext -lX11 -lm -lz

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
