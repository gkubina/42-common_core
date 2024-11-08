NAME = philo

HEADER = philo.h

CC = cc

FLAGS = -Wall -Wextra -Werror
INC = -lpthread

SRC = \
	philo.c \
	timer.c \
	parsehelper.c \
	table.c \
	actions.c \
	actions2.c \
	log.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(INC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY:	clean fclean re bonus
