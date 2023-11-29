NAME 	= so_long

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

INCLUDES	= -I ./includes
SOURCE		= ./source/
LIBRARY 	= -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX	= mlx/



SRC 	= $(SRC)
OBJS	= $(SRC:%.c=%.o)

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(INCLUDES) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
			make clean -C $(MLX)
			rm -rf $(NAME)

re: fclean all