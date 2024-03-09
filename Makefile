NAME = push_swap

NAME_b = checker


SRC = ./Utils_folder/ft_putstr.c ./Utils_folder/ft_strjoin.c push_to_a.c sorting.c target_a_utils.c utils2.c push_to_b_.c target_b.c target_a.c moves_a.c moves_b.c moves_both.c push_swap.c ./Utils_folder/ft_atoi.c utils.c check_args.c ./Utils_folder/ft_split.c parsing.c ./Utils_folder/ft_substr.c

BSRC = ./BONUS/get-next-line/get_next_line_utils.c ./BONUS/get-next-line/get_next_line.c ./BONUS/checker_bonus.c ./BONUS/moves_both_bonus.c ./BONUS/moves_b_bonus.c ./BONUS/moves_a_bonus.c ./BONUS/instruction_bonus.c ./BONUS/checker_utils_bonus.c ./BONUS/utils1_bonus.c  ./BONUS/parsing_bonus.c    ./BONUS/Utils_folder/ft_putstr.c ./BONUS/Utils_folder/ft_strjoin.c  ./BONUS/Utils_folder/ft_atoi.c ./BONUS/Utils_folder/ft_substr.c ./BONUS/Utils_folder/ft_split.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

CC = cc


all : $(NAME)

bonus : $(NAME_b)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(NAME_b): $(BOBJ)
	$(CC) $(BOBJ) -o $(NAME_b)

clean:
	rm -rf $(OBJ) $(BOBJ)

fclean: clean
	rm -rf $(NAME) $(NAME_b)

re: fclean all bonus clean
	