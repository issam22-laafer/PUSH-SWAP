/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:07:00 by lissam            #+#    #+#             */
/*   Updated: 2024/03/09 08:26:18 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	is_sorted(t_data **stack_a)
{
	t_data	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->data < tmp->next->data)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	fill_stack_a(t_numbers *the_numbers, t_data **stack_a)
{
	int	i;

	i = 0;
	while (the_numbers->numbers[i])
	{
		if (if_number(the_numbers->numbers[i]))
			insert_back(stack_a, ft_atoi(the_numbers->numbers[i], the_numbers,
					stack_a));
		else
		{
			freestack(stack_a);
			free_nbrs(the_numbers);
			ft_putstr2("Error\n");
			exit(1);
		}
		i++;
	}
	free_nbrs(the_numbers);
}

void	checker(t_numbers *the_numbers)
{
	t_data	*stack_a;
	t_data	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	fill_stack_a(the_numbers, &stack_a);
	check_doubles(&stack_a);
	instruction(&stack_a, &stack_b);
	if (is_sorted(&stack_a) && count_nodes(&stack_b) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	freestack(&stack_a);
	freestack(&stack_b);
}

int	main(int ac, char **av)
{
	t_numbers	the_numbers;

	check_n_args(ac, av);
	get_numbers(ac, av, &the_numbers);
	checker(&the_numbers);
}
