/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:18:43 by lissam            #+#    #+#             */
/*   Updated: 2024/03/01 19:01:02 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_first_target_a(int a, t_data **stack_b)
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

int	find_first_target_b(int a, t_data **stack_a)
{
	t_data	*tmp;
	int		target;

	tmp = *stack_a;
	target = a;
	while (tmp)
	{
		if (tmp->data > a)
			target = tmp->data;
		tmp = tmp->next;
	}
	if (target == a)
		target = the_small_n(stack_a);
	return (target);
}

void	freestack(t_data **my_stack)
{
	t_data	*tmp;

	if (my_stack)
	{
		while (*my_stack != NULL)
		{
			tmp = (*my_stack)->next;
			free(*my_stack);
			*my_stack = tmp;
		}
		*my_stack = NULL;
	}
}

int	the_small_n(t_data **stack)
{
	t_data	*tmp;
	int		the_small;

	tmp = *stack;
	the_small = tmp->data;
	while (tmp)
	{
		if (tmp->data < the_small)
			the_small = tmp->data;
		tmp = tmp->next;
	}
	return (the_small);
}

int	the_big_n(t_data **stack)
{
	t_data	*tmp;
	int		the_big;

	tmp = *stack;
	the_big = tmp->data;
	while (tmp)
	{
		if (tmp->data > the_big)
			the_big = tmp->data;
		tmp = tmp->next;
	}
	return (the_big);
}
