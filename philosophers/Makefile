NAME = philo


SRCS = ft_atoi.c init_values.c philosophers.c routine.c time_utils.c \
		main_checker.c ft_actions.c create_mtx_and_pth.c

INCLUDE = philosophers.h \

CC = gcc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
#-g3 -fsanitize=thread

%.o: %.c ${INCLUDE}
			@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
			@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
			@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
			@${RM} ${OBJS}

fclean:
			@${RM} ${OBJS}
			@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
