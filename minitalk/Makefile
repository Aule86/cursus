SERVER = server
CLIENT = client

DIR_CLIENT = ft_client.c
DIR_SERVER = ft_server.c
DIR_PRINTF = printf/*.c

FLAGS = -Wall -Werror -Wextra
CC = gcc


all: $(SERVER) $(CLIENT)

$(CLIENT):
		@ gcc $(FLAGS) $(DIR_CLIENT) $(DIR_PRINTF) -o client
		@ echo "Compiling client..."

$(SERVER):
		@ gcc $(FLAGS) $(DIR_SERVER) $(DIR_PRINTF) -o server
		@ echo "Compiling server..."

clean_client:
		@ m -rf client

clean_server:
		@ rm -rf server

fclean: clean
		@ rm -f server
		@ rm -f client

re: fclean all

.PHONY : all clean fclean re