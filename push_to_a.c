/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <lissam@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:43:10 by codespace         #+#    #+#             */
/*   Updated: 2024/03/04 14:51:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min_to_top(int i, t_data **stack_a)
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

void	check_min_position(t_data **stack_a)
{
	int		min_stack;
	t_data	*tmp_a;
	int		i;

	min_stack = the_small_n(stack_a);
	tmp_a = *stack_a;
	i = 0;
	while (tmp_a->data != min_stack)
	{
		i++;
		tmp_a = tmp_a->next;
	}
	get_min_to_top(i, stack_a);
}
