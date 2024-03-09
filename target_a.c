/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:20:35 by lissam            #+#    #+#             */
/*   Updated: 2024/03/09 16:46:54 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves(int index_a, int index_b, t_data **stack_a, t_data **stack_b)
{
	int	nb_moves;

	nb_moves = 0;
	if (index_a <= count_nodes(stack_a) / 2 && index_b <= count_nodes(stack_b)
		/ 2)
	{
		nb_moves = nb_moves + count_moves_top(index_a, index_b);
	}
	else if (index_a > count_nodes(stack_a) / 2
		&& index_b > count_nodes(stack_b) / 2)
	{
		nb_moves = nb_moves + count_moves_bottom(index_a, index_b, stack_a,
				stack_b);
	}
	else
	{
		nb_moves = nb_moves + count_moves_both(index_a, index_b, stack_a,
				stack_b);
	}
	return (nb_moves);
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

void	push(t_data **stack_a, t_data **stack_b, t_elements *elements)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	elements->index_e = 0;
	elements->index_t = 0;
	tmp_a = *stack_a;
	while (tmp_a->data != elements->element)
	{
		tmp_a = tmp_a->next;
		elements->index_e++;
	}
	tmp_b = *stack_b;
	while (tmp_b->data != elements->target)
	{
		tmp_b = tmp_b->next;
		elements->index_t++;
	}
	push_to_b(stack_a, stack_b, elements);
}

void	closest_smaller(int nb, int *target, t_data **stack_b)
{
	t_data	*tmp_b;

	tmp_b = *stack_b;
	*target = find_first_target_a(nb, stack_b);
	while (tmp_b)
	{
		if (tmp_b->data < nb && tmp_b->data > *target)
			*target = tmp_b->data;
		tmp_b = tmp_b->next;
	}
}

void	target_a_push(t_data **stack_a, t_data **stack_b)
{
	t_data		*tmp_a;
	int			target;
	int			number_moves;
	t_elements	elements;

	tmp_a = *stack_a;
	number_moves = INT_MAX;
	while (tmp_a)
	{
		if (find_first_target_a(tmp_a->data, stack_b) == the_big_n(stack_b))
			target = the_big_n(stack_b);
		else
		{
			closest_smaller(tmp_a->data, &target, stack_b);
		}
		if (count_moves(tmp_a->data, target, stack_a, stack_b) < number_moves)
		{
			number_moves = count_moves(tmp_a->data, target, stack_a, stack_b);
			elements.element = tmp_a->data;
			elements.target = target;
		}
		tmp_a = tmp_a->next;
	}
	push(stack_a, stack_b, &elements);
}
