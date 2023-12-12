NAME 	= so_long

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

INCLUDES	= -I ./includes
SOURCE		= source/*.c
GETNEXTLINE	= get_next_line/*c
LIBFT		= libft/*.c
LIBRARY 	= -Lmlx -lmlx -framework OpenGL -framework AppKit
MINILIBX	= mlx/



all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(INCLUDES) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
			make clean -C $(MINILIBX)
			rm -rf $(NAME)

re: fclean all