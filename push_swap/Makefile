NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC = 	algorithm.c \
		ft_add_back.c \
		ft_cases.c \
		ft_cases2.c \
		ft_check_stack.c \
		ft_error.c \
		ft_find.c \
		ft_free.c \
		ft_new_stack.c \
		ft_rotate_type.c \
		ft_rotate.c \
		ft_sort.c \
		ft_utils.c \
		operations.c \
		operations2.c \
		operations3.c \
		push_swap.c \
		ft_sort_3.c \


.SILENT:

$(NAME):
	echo "Compilando..."
	make -C $(LIBFT_DIR) all clean
	$(CC) $(FLAGS) $(SRC) $(LIBFT) -Iincludes -o $(NAME)


all: $(NAME)


clean:
	@rm -rf *.o
	make -C $(LIBFT_DIR) fclean

fclean: clean
	@rm -rf ${NAME}

re: fclean all

.PHONY : all clean fclean re
