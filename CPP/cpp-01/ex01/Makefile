NAME = Moar_brainz

HEADER =

CC = c++

FLAGS = -Wall -Wextra -Werror

DEBUG_FLAGS = -g -std=c++98

SRC = \
	Zombie.cpp \
	zombieHorde.cpp \
	main.cpp \

SRC_BONUS = \

DEP = $(SRC:.cpp=.d)

OBJ = $(SRC:.cpp=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(DEBUG_FLAGS) $(OBJ)

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
