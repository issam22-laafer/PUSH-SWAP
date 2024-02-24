NAME = push_swap

SRC = ft_putstr.c push_swap.c ft_atoi.c utils.c check_args.c ft_split.c parsing.c ft_substr.c

OBJ = $(SRC:.c=.o)

CC = cc


all = $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	