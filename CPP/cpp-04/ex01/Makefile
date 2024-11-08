NAME = Animals_Brains

HEADER =

CC = c++

FLAGS = -Wall -Wextra -Werror

DEBUG_FLAGS = -g -std=c++98

SRC = \
	main.cpp \
	Animal.cpp \
	Dog.cpp \
	Cat.cpp \
	Brain.cpp

SRC_BONUS = \

OBJ = $(SRC:.cpp=.o)

DEP = $(SRC:.cpp=.d)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(LFTA) $(OBJ) $(MLX_LIB)
	$(CC) -o $(NAME) $(FLAGS) $(DEBUG_FLAGS) $(OBJ)

$(LFTA) :
	make -C $(LFTDIR)

$(MLX_LIB) :
	make -C $(MLXDIR)

%.o: %.cpp $(HEADER) Makefile
	$(CC) $(FLAGS) $(DEBUG_FLAGS) -MMD -MP -c $< -o $@

clean :
	rm -f $(OBJ) $(OBJ_BONUS) $(DEP)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : all

-include $(DEP)

.PHONY: all clean fclean re
