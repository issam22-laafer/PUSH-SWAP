/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:25:47 by lissam            #+#    #+#             */
/*   Updated: 2024/03/01 10:26:47 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_3(t_data **stack_a)
{
	t_data	*tmp;
	int		big;

	tmp = *stack_a;
	big = the_big_n(stack_a);
	if (tmp->data == big)
	{
		rotate_a(stack_a);
		ft_putstr("ra\n");
		tmp = *stack_a;
	}
	else if (tmp->next->data == big)
	{
		reverse_rotate_a(stack_a);
		ft_putstr("rra\n");
		tmp = *stack_a;
	}
	if (tmp->data > tmp->next->data)
	{
		swap_a(stack_a);
		ft_putstr("sa\n");
	}
}

int	is_sorted(t_data **stack_a)
{
	t_data	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->data < tmp->next->data)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	turk(t_data **stack_a, t_data **stack_b)
{
	int	number_of_nodes;

	number_of_nodes = count_nodes(stack_a);
	if (number_of_nodes == 4)
	{
		push_b(stack_a, stack_b);
		ft_putstr("pb\n");
	}
	else if (number_of_nodes > 4)
	{
		push_b(stack_a, stack_b);
		ft_putstr("pb\n");
		push_b(stack_a, stack_b);
		ft_putstr("pb\n");
	}
	number_of_nodes = count_nodes(stack_a);
	while (number_of_nodes > 3)
	{
		target_a_push(stack_a, stack_b);
		number_of_nodes--;
	}
	sort_3(stack_a);
	target_b_push(stack_b,stack_a);
}

void	sort(t_data **stack_a, t_data **stack_b)
{
	if (is_sorted(stack_a))
	{
		ft_putstr("Stack is sorted\n");
		return ;
	}
	if (count_nodes(stack_a) > 1 && count_nodes(stack_a) <= 3)
		sort_3(stack_a);
	else if (count_nodes(stack_a) > 3)
		turk(stack_a, stack_b);
}

