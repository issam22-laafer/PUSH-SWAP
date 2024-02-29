NAME = push_swap

SRC = ./Utils_folder/ft_putstr.c sorting.c target.c moves_a.c moves_b.c moves_both.c push_swap.c ./Utils_folder/ft_atoi.c utils.c check_args.c ./Utils_folder/ft_split.c parsing.c ./Utils_folder/ft_substr.c

OBJ = $(SRC:.c=.o)

CC = cc


all : $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all clean
	