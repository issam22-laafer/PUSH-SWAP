/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:20:35 by lissam            #+#    #+#             */
/*   Updated: 2024/02/29 10:04:38 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_first_target(int a, t_data **stack_b)
{
    t_data *tmp;
    int target;

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
    return target;
}

int count_moves(int nb, int target, t_data **stack_a, t_data **stack_b)
{
}

void target_push(t_data **stack_a, t_data **stack_b)
{
    t_data *tmp_a;
    t_data *tmp_b;
    int target;
    int number_moves;

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
            number_moves = count_moves(tmp_a->data, target, stack_a, stack_b);
        tmp_a = tmp_a->next;
    }
}
