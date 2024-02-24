/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:45:20 by lissam            #+#    #+#             */
/*   Updated: 2024/02/24 11:56:36 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_nodes(t_data **stack_a)
{
    t_data  *tmp;
    int     i;

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
    printf("Number of nodes ==> %d\n",count_nodes(stack_a));
    
    t_data *tmp;
    t_data *tmp1;

    
    tmp = *stack_a;
    tmp1 = tmp->next;
    tmp->next = tmp->next->next;
    tmp1->next = tmp;
    
    *stack_a = tmp1;
}