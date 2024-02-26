/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:26:57 by lissam            #+#    #+#             */
/*   Updated: 2024/02/26 19:42:26 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_numbers(int ac, char **av, t_numbers *the_numbers)
{
	if (ac == 2)
	{
		the_numbers->numbers = ft_split(av[1], ' ');
	}
	else
		the_numbers->numbers = av + 1;
}
 
void fill_stack_a(t_numbers *the_numbers, t_data **stack_a)
{
	int i;

	i = 0;
	while (the_numbers->numbers[i])
	{
		if (if_number(the_numbers->numbers[i]))
			insert_back(stack_a, ft_atoi(the_numbers->numbers[i]));
		else
		{
			ft_putstr("Error\n");
			exit(1);
		} 
		i++;
	}
}
void push_swap(t_numbers *the_numbers)
{
	t_data *stack_a;
	t_data *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	fill_stack_a(the_numbers, &stack_a);
	check_doubles(&stack_a);
	sort(&stack_a,&stack_b);

	t_data *tmp;
	tmp = stack_a;
	while (tmp)
	{
		printf("==> %d\n",tmp->data);
		tmp = tmp->next;
	}
	
}
int main(int ac, char **av)
{
	t_numbers the_numbers;

	the_numbers.argc_number = ac;
	check_n_args(ac,av);
	get_numbers(ac, av, &the_numbers);
	push_swap(&the_numbers);
}
