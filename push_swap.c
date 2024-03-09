/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:26:57 by lissam            #+#    #+#             */
/*   Updated: 2024/03/09 08:26:15 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_numbers(int ac, char **av, t_numbers *the_numbers)
{
	int		i;
	int		j;
	char	**tmp;
	char	*tmp2;

	i = 1;
	tmp2 = NULL;
	while (i < ac)
	{
		j = 0;
		tmp = ft_split(av[i], ' ');
		if (!tmp[0])
			free_exit(tmp, tmp2);
		while (tmp[j])
		{
			tmp2 = ft_strjoin(tmp2, " ");
			tmp2 = ft_strjoin(tmp2, tmp[j++]);
		}
		j = 0;
		while (tmp[j])
			free(tmp[j++]);
		(free(tmp), i++);
	}
	the_numbers->numbers = ft_split(tmp2, ' ');
	free(tmp2);
}

void	fill_stack_a(t_numbers *the_numbers, t_data **stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (the_numbers->numbers[i])
	{
		if (if_number(the_numbers->numbers[i]))
			insert_back(stack_a, ft_atoi(the_numbers->numbers[i], the_numbers,
					stack_a));
		else
		{
			freestack(stack_a);
			j = 0;
			while (the_numbers->numbers[j])
			{
				free(the_numbers->numbers[j]);
				j++;
			}
			free(the_numbers->numbers);
			ft_putstr2("Error\n");
			exit(1);
		}
		i++;
	}
}

void	push_swap(t_numbers *the_numbers)
{
	t_data	*stack_a;
	t_data	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	fill_stack_a(the_numbers, &stack_a);
	check_doubles(&stack_a, the_numbers);
	sort(&stack_a, &stack_b);
	freestack(&stack_a);
	freestack(&stack_b);
}

int	main(int ac, char **av)
{
	t_numbers	the_numbers;
	int			j;

	j = 0;
	the_numbers.argc_number = ac;
	check_n_args(ac, av);
	get_numbers(ac, av, &the_numbers);
	push_swap(&the_numbers);
	while (the_numbers.numbers[j])
	{
		free(the_numbers.numbers[j]);
		j++;
	}
	free(the_numbers.numbers);
}
