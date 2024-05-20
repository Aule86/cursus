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


OBJ = ${SRC:.c=.o}


.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	make -C $(LIBFT_DIR)
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

$(LIBFT):
	make -C $(LIBFT) all clean

all: ${NAME}


clean:
	@rm -rf *.o

fclean: clean
	@rm -rf ${NAME}

re: fclean all

.PHONY : all clean fclean re
