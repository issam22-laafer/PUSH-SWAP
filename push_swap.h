/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:16:16 by lissam            #+#    #+#             */
/*   Updated: 2024/03/09 16:49:36 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct elements
{
	int			element;
	int			target;
	int			index_e;
	int			index_t;
}				t_elements;

typedef struct numbers
{
	char		**numbers;
	int			argc_number;
}				t_numbers;
void			freestack(t_data **my_stack);
void			ft_putstr(char *str);
void			ft_putstr2(char *str);
void			check_n_args(int ac, char **av);
char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			insert_back(t_data **head, int nb);
int				if_number(char *str);
int				ft_atoi(char *str, t_numbers *the_numbers, t_data **stack_a);
void			check_doubles(t_data **stack_a, t_numbers *the_numbers);
int				count_nodes(t_data **stack);
void			swap_a(t_data **stack_a);
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
void			sort(t_data **satck_a, t_data **satck_b);
void			target_a_push(t_data **stack_a, t_data **stack_b);
int				the_big_n(t_data **stack);
void			push_to_b(t_data **stack_a, t_data **stack_b,
					t_elements *elements);
int				min_index(int i, int j);
int				max_index(int i, int j);
int				count_moves_top(int index_a, int index_b);
int				count_moves_bottom(int index_a, int index_b, t_data **stack_a,
					t_data **stack_b);
int				count_moves_a(int index_a, t_data **stack_a);
int				count_moves_b(int index_b, t_data **stack_b);
int				count_moves_both(int index_a, int index_b, t_data **stack_a,
					t_data **stack_b);
int				find_first_target_a(int a, t_data **stack_b);
int				find_first_target_b(int a, t_data **stack_a);
int				the_small_n(t_data **stack);
void			target_b_push(t_data **stack_b, t_data **stack_a);
void			check_min_position(t_data **stack_a);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *src);
void			free_exit(char **tmp, char *tmp2);

#endif