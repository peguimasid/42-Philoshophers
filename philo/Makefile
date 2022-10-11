NAME=philo

SRCS	= src/main.c		\
				src/common.c	\
				src/utils.c	\
				src/parse.c	\
				src/routine.c	\
				src/thread.c	\
				src/monitor.c	\

OBJ	= $(SRCS:.c=.o)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re