NAME = Minitalk
SERVER = server
CLIENT = client
CC = cc 
FLAGS = -Wall -Wextra -Werror 

LFTDIR = ./libft

LFTA = $(LFTDIR)/libft.a

SRC_SERVER = \
	minitalk_server.c \


SRC_CLIENT = \
	minitalk_client.c \


SRC_SERVER_BONUS = \
	minitalk_server_bonus.c \
	utils.c

SRC_CLIENT_BONUS = \
	minitalk_client_bonus.c \


OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

B_SRC = \

B_OBJ = $(B_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(CLIENT) $(SERVER)

$(CLIENT) : $(LFTA) $(OBJ_CLIENT)
	$(CC) -o $(CLIENT) $(FLAGS) $(OBJ_CLIENT) -L$(LFTDIR) -lft

$(SERVER) : $(LFTA) $(OBJ_SERVER)
	$(CC) -o $(SERVER) $(FLAGS) $(OBJ_SERVER) -L$(LFTDIR) -lft

$(LFTA) :  
	make -C $(LFTDIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS) 
	make -C $(LFTDIR) clean

fclean : clean
	rm -f $(CLIENT) $(SERVER)
	make -C $(LFTDIR) fclean

re : fclean all

bonus : $(LFTA) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
	rm -f $(CLIENT) $(SERVER)
	$(CC) -o $(CLIENT) $(FLAGS) $(OBJ_CLIENT_BONUS) -L$(LFTDIR) -lft
	$(CC) -o $(SERVER) $(FLAGS) $(OBJ_SERVER_BONUS) -L$(LFTDIR) -lft
