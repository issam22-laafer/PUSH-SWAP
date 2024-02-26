/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:25:47 by lissam            #+#    #+#             */
/*   Updated: 2024/02/26 21:52:35 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int the_big_a(t_data **stack_a)
{
    t_data *tmp;
    int the_big;

    tmp = *stack_a;
    the_big = tmp->data;
    while (tmp)
    {
        if (tmp->data > the_big)
            the_big = tmp->data;
        tmp = tmp->next;
    }
    return the_big;
}

void sort_3(t_data **stack_a)
{
    t_data *tmp;
    int big;

    tmp = *stack_a;
    big = the_big_a(stack_a);
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

void sort(t_data **stack_a, t_data **stack_b)
{
    t_data *tmp;

    if (count_nodes(stack_a) > 1 && count_nodes(stack_a) <= 3)
        sort_3(stack_a);
    tmp = *stack_b;
}