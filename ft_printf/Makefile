NAME = libftprintf.a
CC = cc 
FLAGS = -Wall -Wextra -Werror 

LFTDIR = ./libft

LFTA = libft.a

SRC = \
	ft_printf.c \
	fill_arginfo.c \
	ft_printarg.c \
	init_arginfo.c \
	printstr.c \
	printperc.c \
	printint.c \
	printhex.c \
	printuint.c \
	printchar.c \
	printpoint.c \
	reset_flags.c \
	ft_putnbr_unsig_fd.c \
	intlength.c \
	ft_putnbr_base_16.c \

OBJ = $(SRC:.c=.o)

B_SRC = \




B_OBJ = $(B_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LFTA) $(OBJ)
	cp $(LFTA) $(NAME)
	ar rcs $@ $(OBJ)

$(LFTA) :  
	make -C $(LFTDIR) bonus
	cp $(LFTDIR)/$(LFTA) .

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(B_OBJ)
	make -C $(LFTDIR) clean

fclean : clean
	rm -f $(NAME) $(LFTA)
	make -C $(LFTDIR) fclean

re : fclean all

bonus : $(NAME)  

