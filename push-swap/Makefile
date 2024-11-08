NAME = push_swap
CC = cc 
FLAGS = -Wall -Wextra -Werror 

LFTDIR = ./libft

LFTA = $(LFTDIR)/libft.a

SRC = \
	cost_analyzers.c \
	manipulations.c \
	operators.c \
	push_swap.c \
	rotation_list.c \
	sort_stacks.c \
	utils.c \
	fill_stack_helpers.c \
	print_stacks.c \
	sort_big_stack_helpers.c \
	sort_big_stack_helpers2.c \
	stack_information.c \

OBJ = $(SRC:.c=.o)

B_SRC = \

B_OBJ = $(B_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LFTA) $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) -L$(LFTDIR) -lft

$(LFTA) :  
	make -C $(LFTDIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(B_OBJ)
	make -C $(LFTDIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(LFTDIR) fclean

re : fclean all

bonus : $(NAME)  

