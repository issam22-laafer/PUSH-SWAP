

#ifndef CHECKER_BONUS_H
#define CHECKER_BONUS_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct node
{
	int			data;
	struct node	*next;
}				t_data;

typedef struct numbers
{
	char		**numbers;
	int			argc_number;
}				t_numbers;

int	check_lenght(char *str);
int	if_number(char *str);
void	check_doubles(t_data **stack_a);
void free_nbrs(t_numbers *the_numbers);
void	freestack(t_data **my_stack);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen2(char *str);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
int	ft_atoi(char *str, t_numbers *the_numbers, t_data **stack_a);
void	insert_back(t_data **head, int nb);
int	count_nodes(t_data **stack);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	check_n_args(int ac, char **av);
void	ft_putstr(char *str);
char	*get_next_line(int fd);
void instruction(t_data **stack_a, t_data **stack_b);
void swap_a(t_data **stack_a);
void			rotate_a(t_data **stack_a);
void			reverse_rotate_a(t_data **stack_a);
void			push_b(t_data **stack_a, t_data **stack_b);
void			swap_b(t_data **stack_b);
void			rotate_b(t_data **stack_b);
void			reverse_rotate_b(t_data **stack_b);
void			push_a(t_data **stack_b, t_data **stack_a);
void			ss(t_data **stack_a, t_data **stack_b);
void			rr(t_data **stack_a, t_data **stack_b);
void			rrr(t_data **stack_a, t_data **stack_b);

#endif