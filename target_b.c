/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:18:16 by codespace         #+#    #+#             */
/*   Updated: 2024/03/04 14:20:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves_to_push(int i, t_data **stack_a)
{
	if (i <= count_nodes(stack_a) / 2)
	{
		while (i > 0)
		{
			rotate_a(stack_a);
			ft_putstr("ra\n");
			i--;
		}
	}
	else
	{
		while (i < count_nodes(stack_a))
		{
			reverse_rotate_a(stack_a);
			ft_putstr("rra\n");
			i++;
		}
	}
}

void	push_to_a(int target, t_data **stack_b, t_data **stack_a)
{
	t_data	*tmp_a;
	int		i;

	tmp_a = *stack_a;
	i = 0;
	while (tmp_a->data != target)
	{
		i++;
		tmp_a = tmp_a->next;
	}
	moves_to_push(i, stack_a);
	push_a(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	closest_bigger(int nb, int *target, t_data **stack_a)
{
	t_data	*tmp_a;

	tmp_a = *stack_a;
	*target = find_first_target_b(nb, stack_a);
	while (tmp_a)
	{
		if (tmp_a->data > nb && tmp_a->data < *target)
			*target = tmp_a->data;
		tmp_a = tmp_a->next;
	}
}

void	target_b_push(t_data **stack_b, t_data **stack_a)
{
	t_data	*tmp_b;
	int		target;

	tmp_b = *stack_b;
	if (find_first_target_b(tmp_b->data, stack_a) == the_small_n(stack_a))
		target = the_small_n(stack_a);
	else
	{
		closest_bigger(tmp_b->data, &target, stack_a);
	}
	push_to_a(target, stack_b, stack_a);
}
