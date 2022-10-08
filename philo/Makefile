NAME=philo

SRCS	= src/main.c		\
				src/init.c	\
				src/common.c	\
				src/libc.c	\
				src/validate_args.c	\

OBJ	= $(SRCS:.c=.o)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME) $(LIBFTPRINTF)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re