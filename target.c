/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:20:35 by lissam            #+#    #+#             */
/*   Updated: 2024/03/01 12:19:21 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	*target = find_first_target(nb, stack_b);
	while (tmp_b)
	{
		if (tmp_b->data < nb && tmp_b->data > *target)
			*target = tmp_b->data;
		tmp_b = tmp_b->next;
	}
}

void	target_push(t_data **stack_a, t_data **stack_b)
{
	t_data		*tmp_a;
	int			target;
	int			number_moves;
	t_elements	elements;

	tmp_a = *stack_a;
	number_moves = 500;
	while (tmp_a)
	{
		if (find_first_target(tmp_a->data, stack_b) == the_big_n(stack_b))
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
