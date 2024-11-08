CC = cc
CFLAGS = -Werror -Wextra -Wall -g 

SRC =   main.c\
		./printf/ft_printf.c\
		./printf/ft_printp.c\
		./printf/ft_printupperx.c\
		./printf/ft_printx.c\
		./printf/ft_putchar_fd.c\
		./printf/ft_putnbr_fd.c\
		./printf/ft_putstr_fd.c\
		./gnl/get_next_line.c\
		./gnl/get_next_line_utils.c\
		./libft/ft_isalpha.c\
        ./libft/ft_isdigit.c\
        ./libft/ft_isalnum.c\
        ./libft/ft_isascii.c\
        ./libft/ft_isprint.c\
        ./libft/ft_toupper.c\
        ./libft/ft_tolower.c\
        ./libft/ft_bzero.c\
        ./libft/ft_memset.c\
        ./libft/ft_memcpy.c\
        ./libft/ft_memmove.c\
        ./libft/ft_memchr.c\
        ./libft/ft_memcmp.c\
        ./libft/ft_strlen.c\
        ./libft/ft_strlcpy.c\
        ./libft/ft_strlcat.c\
        ./libft/ft_strchr.c\
        ./libft/ft_strrchr.c\
        ./libft/ft_strncmp.c\
        ./libft/ft_strnstr.c\
        ./libft/ft_atoi.c\
        ./libft/ft_calloc.c\
        ./libft/ft_strdup.c\
        ./libft/ft_substr.c\
        ./libft/ft_strjoin.c\
        ./libft/ft_strtrim.c\
        ./libft/ft_split.c\
        ./libft/ft_itoa.c\
        ./libft/ft_strmapi.c\
        ./libft/ft_striteri.c\
        ./libft/ft_putchar_fd.c\
        ./libft/ft_putendl_fd.c\
        ./libft/ft_putnbr_fd.c\
        ./libft/ft_putstr_fd.c\
		./libft/ft_lstnew.c\
        ./libft/ft_lstadd_front.c\
        ./libft/ft_lstsize.c\
        ./libft/ft_lstlast.c\
        ./libft/ft_lstadd_back.c\
        ./libft/ft_lstdelone.c\
        ./libft/ft_lstclear.c\
        ./libft/ft_lstiter.c\
        ./libft/ft_lstmap.c\
        ./parsing/manage_entry.c\
        ./parsing/check_separators.c\
        ./parsing/only_spaces.c\
        ./parsing/free_hd.c\
		./tokens/create_tokens.c\
		./tokens/check_tokens.c\
		./tokens/expand_vars.c\
        ./tokens/expand_vars_2.c\
		./tokens/remove_quotes.c\
        ./tokens/add_quotes.c\
        ./destroy/destroy_structs.c\
        ./destroy/error_handler.c\
        ./destroy/destroy_commands.c\
        ./signal_handling/signal_handlers.c\
        ./buildins/cd.c\
        ./buildins/cd_bis.c\
        ./buildins/echo.c\
        ./buildins/env.c\
        ./buildins/exit.c\
        ./buildins/export.c\
        ./buildins/pwd.c\
        ./buildins/unset.c\
        ./parsing/to_lst.c\
        ./parsing/open_files.c\
        ./executing/execute.c\
        ./executing/checks_builtins.c\
        ./executing/manage_fd.c\
        ./executing/utils_execute.c\

OBJ = $(SRC:.c=.o)

HEADER = minishell.h

NAME = minishell

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lreadline

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
