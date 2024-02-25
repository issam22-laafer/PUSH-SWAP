/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:26:57 by lissam            #+#    #+#             */
/*   Updated: 2024/02/24 18:21:21 by lissam           ###   ########.fr       */
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
	int i;

	stack_a = NULL;
	i = 0;
	fill_stack_a(the_numbers, &stack_a);
	check_doubles(&stack_a);
	t_data *temp;
	swap_a(&stack_a);
	rotate_a(&stack_a);
	temp = stack_a;
	while (temp)
	{
		printf("---->%d\n", temp->data);
		temp = temp->next;
	}
	printf("================\n");
	reverse_rotate_a(&stack_a);

	temp = stack_a;
	while (temp)
	{
		printf("---->%d\n", temp->data);
		temp = temp->next;
	}
}
int main(int ac, char **av)
{
	t_numbers the_numbers;

	the_numbers.argc_number = ac;
	check_n_args(ac);
	get_numbers(ac, av, &the_numbers);
	push_swap(&the_numbers);
	// creat_stack_a(&the_numbers,&stack_a);
	// int			i;
	// i = 0;
	// while (the_numbers.numbers[i])
	// {
	// 	printf("%s\n", the_numbers.numbers[i]);
	// 	i++;
	// }
}
