NAME=philo

SRCS	= src/main.c		\
				src/parse/main.c	\
				src/utils/error.c	\
				src/utils/ft_atoi.c	\

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