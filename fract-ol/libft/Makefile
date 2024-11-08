NAME = libft.a
CC = gcc 
FLAGS = -Wall -Wextra -Werror

SRC = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_strdup.c \
	ft_calloc.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
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
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \

OBJ = $(SRC:.c=.o)

B_SRC = \
		
B_OBJ = $(B_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $@ $?

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(NAME)
