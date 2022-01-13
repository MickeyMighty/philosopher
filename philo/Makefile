NAME	=	philo

CC		=	gcc

RM		=	rm -f

CFLAGS			= -Wall -Wextra -Werror -I.

SRCS	=	./srcs/main.c \
			./srcs/action.c \
			./srcs/init_and_error.c \
			./srcs/threads.c \
			./srcs/tools.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re f
