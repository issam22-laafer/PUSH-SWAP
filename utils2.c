/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:18:43 by lissam            #+#    #+#             */
/*   Updated: 2024/03/01 12:20:57 by lissam           ###   ########.fr       */
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
