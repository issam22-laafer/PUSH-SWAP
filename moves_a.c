/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:45:20 by lissam            #+#    #+#             */
/*   Updated: 2024/02/25 10:26:14 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_data **stack_a)
{
    // printf("Number of nodes ==> %d\n",count_nodes(stack_a));

    if (count_nodes(stack_a) > 1)
    {
        t_data *tmp;
        t_data *tmp1;

        tmp = *stack_a;
        tmp1 = tmp->next;
        tmp->next = tmp->next->next;
        tmp1->next = tmp;

        *stack_a = tmp1;
    }
}

void rotate_a(t_data **stack_a)
{
    if (count_nodes(stack_a) > 1)
    {

        t_data *tmp;
        t_data *tmp1;

        tmp = *stack_a;
        tmp1 = *stack_a;

        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = *stack_a;
        *stack_a = tmp1->next;
        tmp1->next = NULL;
    }
}

void reverse_rotate_a(t_data **stack_a)
{
    if (count_nodes(stack_a) > 1)
    {
        t_data *tmp;
        t_data *second_last;

        tmp = *stack_a;
        second_last = NULL;

        while (tmp->next)
        {
            second_last = tmp;
            tmp = tmp->next;
        }
        tmp->next = *stack_a;
        *stack_a = tmp;
        second_last->next = NULL;
    }
}

void push_b(t_data **stack_a, t_data **stack_b)
{
    if(count_nodes(stack_a) > 0)
    {
        t_data *tmp_a;
        t_data *tmp_b;

        tmp_a = *stack_a;
        tmp_b = *stack_b;
        *stack_a = tmp_a->next;
        *stack_b = tmp_a;
        tmp_a->next = tmp_b;
    }
}
