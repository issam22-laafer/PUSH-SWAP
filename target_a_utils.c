/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_a_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:46:17 by lissam            #+#    #+#             */
/*   Updated: 2024/03/10 13:58:40 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_moves_top(int index_a, int index_b)
{
	int	nb_moves;
	int	min;

	nb_moves = 0;
	min = min_index(index_a, index_b);
	while (min > 0)
	{
		nb_moves++;
		index_a--;
		index_b--;
		min--;
	}
	while (index_a > 0)
	{
		nb_moves++;
		index_a--;
	}
	while (index_b > 0)
	{
		nb_moves++;
		index_b--;
	}
	return (nb_moves);
}

int	count_moves_bottom(int index_a, int index_b, t_data **stack_a,
		t_data **stack_b)
{
	int	nb_moves;
	int	cna;
	int	cnb;

	cna = count_nodes(stack_a);
	cnb = count_nodes(stack_b);
	nb_moves = 0;
	while (index_a < cna && index_b < cnb)
	{
		index_a++;
		index_b++;
		nb_moves++;
	}
	while (index_b < cnb)
	{
		nb_moves++;
		index_b++;
	}
	while (index_a < cna)
	{
		nb_moves++;
		index_a++;
	}
	return (nb_moves);
}

int	count_moves_a(int index_a, t_data **stack_a)
{
	int	nb_moves;
	int	cna;

	nb_moves = 0;
	cna = count_nodes(stack_a);
	if (index_a <= cna / 2)
	{
		while (index_a > 0)
		{
			nb_moves++;
			index_a--;
		}
	}
	else
	{
		while (index_a < cna)
		{
			nb_moves++;
			index_a++;
		}
	}
	return (nb_moves);
}

int	count_moves_b(int index_b, t_data **stack_b)
{
	int	nb_moves;
	int	cnb;

	nb_moves = 0;
	cnb = count_nodes(stack_b);
	if (index_b <= cnb / 2)
	{
		while (index_b > 0)
		{
			nb_moves++;
			index_b--;
		}
	}
	else
	{
		while (index_b < cnb)
		{
			nb_moves++;
			index_b++;
		}
	}
	return (nb_moves);
}

int	count_moves_both(int index_a, int index_b, t_data **stack_a,
		t_data **stack_b)
{
	int	nb_moves;

	nb_moves = 0;
	nb_moves = nb_moves + count_moves_a(index_a, stack_a);
	nb_moves = nb_moves + count_moves_b(index_b, stack_b);
	return (nb_moves);
}
