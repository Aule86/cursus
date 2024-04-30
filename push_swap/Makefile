NAME = push_swap

SRCS = $(wildcard *.c)

FLAGS = -Wall -Wextra -Werror


$(NAME):
		@ cd libft && make libft.a && make clean
		@ gcc $(FLAGS) $(SRCS) libft/libft.a -o push_swap
		@ echo "Compiling push_swap.."


all : $(NAME)

clear :
		@ rm -rf

fclean : clean
		@ rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
