/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_both_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:07:33 by lissam            #+#    #+#             */
/*   Updated: 2024/03/08 18:07:34 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ss(t_data **stack_a, t_data **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	rr(t_data **stack_a, t_data **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	rrr(t_data **stack_a, t_data **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
