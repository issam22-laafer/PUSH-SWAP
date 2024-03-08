/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:07:30 by lissam            #+#    #+#             */
/*   Updated: 2024/03/08 18:07:31 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_b(t_data **stack_b)
{
	t_data	*tmp;
	t_data	*tmp1;

	if (count_nodes(stack_b) > 1)
	{
		tmp = *stack_b;
		tmp1 = tmp->next;
		tmp->next = tmp->next->next;
		tmp1->next = tmp;
		*stack_b = tmp1;
	}
}

void	rotate_b(t_data **stack_b)
{
	t_data	*tmp;
	t_data	*tmp1;

	if (count_nodes(stack_b) > 1)
	{
		tmp = *stack_b;
		tmp1 = *stack_b;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = *stack_b;
		*stack_b = tmp1->next;
		tmp1->next = NULL;
	}
}

void	reverse_rotate_b(t_data **stack_b)
{
	t_data	*tmp;
	t_data	*second_last;

	if (count_nodes(stack_b) > 1)
	{
		tmp = *stack_b;
		second_last = NULL;
		while (tmp->next)
		{
			second_last = tmp;
			tmp = tmp->next;
		}
		tmp->next = *stack_b;
		*stack_b = tmp;
		second_last->next = NULL;
	}
}

void	push_a(t_data **stack_b, t_data **stack_a)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	if (count_nodes(stack_b) > 0)
	{
		tmp_a = *stack_a;
		tmp_b = *stack_b;
		*stack_b = tmp_b->next;
		*stack_a = tmp_b;
		tmp_b->next = tmp_a;
	}
}
