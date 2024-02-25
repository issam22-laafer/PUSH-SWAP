/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:45:20 by lissam            #+#    #+#             */
/*   Updated: 2024/02/24 18:23:17 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_nodes(t_data **stack_a)
{
    t_data *tmp;
    int i;

    tmp = *stack_a;
    i = 0;
    while (tmp)
    {
        i++;
        tmp = tmp->next;
    }
    return (i);
}

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
