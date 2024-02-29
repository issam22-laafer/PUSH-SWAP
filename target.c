/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:20:35 by lissam            #+#    #+#             */
/*   Updated: 2024/02/29 12:05:04 by lissam           ###   ########.fr       */
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

void push_to_b(t_data **stack_a,t_data **stack_b,int nb,int target)
{
    t_data *tmp_a;
    t_data *tmp_b;
    int i;
    int j;

    i = 0;
    j = 0;
    tmp_a = *stack_a;
    while (tmp_a->data != nb)
    {
        i++;
        tmp_a = tmp_a->next;
    }
    if(i <= count_nodes(stack_a)/2)
    {
        tmp_a = *stack_a;
        while (tmp_a->data != nb)
        {
            rotate_a(stack_a);
            tmp_a = *stack_a;
        }
        
    }
    else
    {
        tmp_a = *stack_a;
        while (tmp_a->data != nb)
        {
            reverse_rotate_a(stack_a);
            tmp_a = *stack_a;
        }
    }
    tmp_b = *stack_b;
    while (tmp_b->data != target)
    {
        j++;
        tmp_b = tmp_b->next;
    }
    if(j <= count_nodes(stack_b)/2)
    {
        tmp_b = *stack_b;
        while (tmp_b->data != target)
        {
            rotate_b(stack_b);
            tmp_b = *stack_b;
        }
        
    }
    else
    {
        tmp_b = *stack_b;
        while (tmp_b->data != target)
        {
            reverse_rotate_b(stack_b);
            tmp_b = *stack_b;
        }
    }
    push_b(stack_a,stack_b);
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
            printf("Number of moves required to push %d to stack b is  =>  %d\n",tmp_a->data ,number_moves);
		}
		tmp_a = tmp_a->next;
	}
    push_to_b(stack_a,stack_b,the_nb,target);
}



