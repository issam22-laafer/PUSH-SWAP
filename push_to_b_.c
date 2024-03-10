/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 08:50:14 by lissam            #+#    #+#             */
/*   Updated: 2024/03/10 10:37:30 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate_both(t_data **stack_a, t_data **stack_b, int i, int j)
{
	int	min;

	min = min_index(i, j);
	while (min > 0)
	{
		rr(stack_a, stack_b);
		ft_putstr("rr\n");
		min--;
		i--;
		j--;
	}
	while (j > 0)
	{
		rotate_b(stack_b);
		ft_putstr("rb\n");
		j--;
	}
	while (i > 0)
	{
		rotate_a(stack_a);
		ft_putstr("ra\n");
		i--;
	}
}

void	do_reverse_rotate_both(t_data **stack_a, t_data **stack_b, int i, int j)
{
	int	min;

	min = min_index(i, j);
	while (i < count_nodes(stack_a) && j < count_nodes(stack_b))
	{
		rrr(stack_a, stack_b);
		ft_putstr("rrr\n");
		min++;
		i++;
		j++;
	}
	while (j < count_nodes(stack_b))
	{
		reverse_rotate_b(stack_b);
		ft_putstr("rrb\n");
		j++;
	}
	while (i < count_nodes(stack_a))
	{
		reverse_rotate_b(stack_a);
		ft_putstr("rra\n");
		i++;
	}
}

void	do_one_by_one_a(t_data **stack_a, int i)
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

void	do_one_by_one_b(t_data **stack_b, int j)
{
	if (j <= count_nodes(stack_b) / 2)
	{
		while (j > 0)
		{
			rotate_b(stack_b);
			ft_putstr("rb\n");
			j--;
		}
	}
	else
	{
		while (j < count_nodes(stack_b))
		{
			reverse_rotate_b(stack_b);
			ft_putstr("rrb\n");
			j++;
		}
	}
}

void	push_to_b(t_data **stack_a, t_data **stack_b, t_elements *elements)
{
	int	i;
	int	j;

	i = elements->index_e;
	j = elements->index_t;
	if (i <= count_nodes(stack_a) / 2 && j <= count_nodes(stack_b) / 2)
	{
		do_rotate_both(stack_a, stack_b, i, j);
	}
	else if (i > count_nodes(stack_a) / 2 && j > count_nodes(stack_b) / 2)
	{
		do_reverse_rotate_both(stack_a, stack_b, i, j);
	}
	else
	{
		do_one_by_one_a(stack_a, i);
		do_one_by_one_b(stack_b, j);
	}
	push_b(stack_a, stack_b);
	ft_putstr("pb\n");
}
