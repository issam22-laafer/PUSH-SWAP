/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:51:02 by lissam            #+#    #+#             */
/*   Updated: 2024/02/25 10:59:46 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ss(t_data **stack_a,t_data **stack_b)
{
    swap_a(stack_a);
    swap_b(stack_b);
}

void rr(t_data **stack_a,t_data **stack_b)
{
    rotate_a(stack_a);
    rotate_b(stack_b);
}

void rrr(t_data **stack_a,t_data **stack_b)
{
    reverse_rotate_a(stack_a);
    reverse_rotate_b(stack_b);
}