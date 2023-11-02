NAME	= libftprintf.a

SRCS	=	ft_printf.c \
			ft_printf_formats.c \
			ft_printf_adress.c \
			ft_printf_hexa.c


OBJS    = $(SRCS:.c=.o)

LIBC	=	ar rcs
CC		=	gcc
RM      =	rm -f
CFLAGS  =	-Wall -Wextra -Werror
NAME    =	libftprintf.a

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) -c $(CFLAGS) $(SRCS)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
