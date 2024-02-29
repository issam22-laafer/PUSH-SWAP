/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:20:35 by lissam            #+#    #+#             */
/*   Updated: 2024/02/29 15:36:06 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_first_target(int a, t_data **stack_b)
{
	t_data	*tmp;
	int		target;

	tmp = *stack_b;
	target = a;
	while (tmp)
	{
		if (tmp->data < a)
			target = tmp->data;
		tmp = tmp->next;
	}
	if (target == a)
		target = the_big_n(stack_b);
	return (target);
}

int	moves(int index_a, int index_b, t_data **stack_a, t_data **stack_b)
{
	int	nb_nodes_a;
	int	nb_nodes_b;
	int	nb_moves_a;
	int	nb_moves_b;

	nb_nodes_a = count_nodes(stack_a);
	nb_nodes_b = count_nodes(stack_b);
	if (index_a <= nb_nodes_a / 2)
		nb_moves_a = index_a;
	else
		nb_moves_a = nb_nodes_a - index_a;
	if (index_b <= nb_nodes_b / 2)
		nb_moves_b = index_b;
	else
		nb_moves_b = nb_nodes_b - index_b;
	return (nb_moves_a + nb_moves_b);
}

int	count_moves(int nb, int target, t_data **stack_a, t_data **stack_b)
{
	t_data	*tmp_a;
	t_data	*tmp_b;
	int		index_a;
	int		index_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	index_a = 0;
	index_b = 0;
	while (tmp_a->data != nb)
	{
		index_a++;
		tmp_a = tmp_a->next;
	}
	while (tmp_b->data != target)
	{
		index_b++;
		tmp_b = tmp_b->next;
	}
	return (moves(index_a, index_b, stack_a, stack_b));
}

void	push_to_b(t_data **stack_a, t_data **stack_b, int nb, int target)
{
	t_data	*tmp_a;
	t_data	*tmp_b;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp_a = *stack_a;
	while (tmp_a->data != nb)
	{
		tmp_a = tmp_a->next;
		i++;
	}
	printf("index of %d target is %d\n",nb,i);

	if (i <= count_nodes(stack_a) / 2)
	{
		while (i > 0)
		{
			rotate_a(stack_a);
			i--;
		}
	}
	else
	{
		while (i < count_nodes(stack_a))
		{
			reverse_rotate_a(stack_a);
			i++;
		}
	}
	tmp_b = *stack_b;
	while (tmp_b->data != target)
	{
		tmp_b = tmp_b->next;
		j++;
	}
	printf("index of %d target is %d\n",target,j);
	if (j <= count_nodes(stack_b) / 2)
	{
		while (j > 0)
		{
			rotate_b(stack_b);
			j--;
		}
	}
	else
	{
		while (j < count_nodes(stack_b))
		{
			reverse_rotate_b(stack_b);
			j++;
		}
	}
	push_b(stack_a, stack_b);
	ft_putstr("pb\n");
}

void	target_push(t_data **stack_a, t_data **stack_b)
{
	t_data	*tmp_a;
	t_data	*tmp_b;
	int		target;
	int		number_moves;
	int		the_nb;
	int		the_target;

	tmp_a = *stack_a;
	number_moves = 500;
	while (tmp_a)
	{
		if (find_first_target(tmp_a->data, stack_b) == the_big_n(stack_b))
			target = the_big_n(stack_b);
		else
		{
			tmp_b = *stack_b;
			target = find_first_target(tmp_a->data, stack_b);
			while (tmp_b)
			{
				if (tmp_b->data < tmp_a->data && tmp_b->data > target)
					target = tmp_b->data;
				tmp_b = tmp_b->next;
			}
		}
		if (count_moves(tmp_a->data, target, stack_a, stack_b) < number_moves)
		{
			number_moves = count_moves(tmp_a->data, target, stack_a, stack_b);
			the_nb = tmp_a->data;
			the_target = target;
		}
		tmp_a = tmp_a->next;
	}
	printf("The number is %d : target => %d =>  MOves :%d\n", the_nb,
		the_target, number_moves);
	push_to_b(stack_a, stack_b, the_nb, the_target);
}
