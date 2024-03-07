
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
		while (tmp[j])
		{
			tmp2 = ft_strjoin(tmp2, " ");
			tmp2 = ft_strjoin(tmp2, tmp[j]);
			j++;
		}
		j = 0;
		while (tmp[j])
			free(tmp[j++]);
		free(tmp);
		i++;
	}
	the_numbers->numbers = ft_split(tmp2, ' ');
	free(tmp2);
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
			ft_putstr("Error\n");
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
	t_data	*tmp;
	printf("===========Stack A==========\n");
	tmp = stack_a;
	while (tmp)
	{
		printf("==> %d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("===========Stack B==========\n");
	tmp = stack_b;
	while (tmp)
	{
		printf("==> %d\n", tmp->data);
		tmp = tmp->next;
	}
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
