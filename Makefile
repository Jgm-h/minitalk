SERVER = server
CLIENT = client
libft = libft
libft_dir = ./libft
INC_DIR = ./includes


CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -r

all: $(SERVER) $(CLIENT)

$(SERVER):
	make all -C $(libft)/
	$(CC) $(CFLAGS)  server.c $(libft_dir)/libft.a -o  server

$(CLIENT):
	make all -C $(libft)/
	$(CC) $(CFLAGS)  client.c $(libft_dir)/libft.a -o client

all: all

server: $(SERVER)

client: $(CLIENT)

clean:
	make clean -C $(libft)/
	$(RM) $(CLIENT) $(SERVER)

fclean:
	make fclean -C $(libft)/
	$(RM) $(CLIENT) $(SERVER)

re: fclean all