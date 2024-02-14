NAME 	= so_long

CFLAGS = -Wall -Werror -Wextra -framework OpenGL -framework AppKit -g3
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

MLX_DIR = minilibx/
MLX = $(MLX_DIR)libmlx.a

SRCS = so_long.c errors.c read_map.c graphics.c errors_content.c controls.c right_move.c flood_fill.c
GETNEXTLINE = get_next_line/*.c
PRINTF = printf/*.c

HDRS = so_long.h

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(SRCS) $(HDRS)
	gcc $(CFLAGS) $(SRCS) $(LIBFT) $(GETNEXTLINE) $(PRINTF) $(MLX) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all clean

$(MLX):
	make -C $(MLX_DIR) all

clean:
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
