/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 08:49:28 by lissam            #+#    #+#             */
/*   Updated: 2024/03/04 15:03:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_number(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 11)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	check_doubles(t_data **stack_a, t_numbers *the_numbers)
{
	t_data	*temp1;
	t_data	*temp2;
	int		j;

	temp1 = *stack_a;
	while (temp1)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->data == temp2->data)
			{
				ft_putstr("Eroor\n");
				freestack(stack_a);
				j = 0;
				while (the_numbers->numbers[j])
					free(the_numbers->numbers[j++]);
				free(the_numbers->numbers);
				exit(1);
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}
