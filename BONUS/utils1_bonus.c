/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:07:40 by lissam            #+#    #+#             */
/*   Updated: 2024/03/09 22:02:10 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_nbrs(t_numbers *the_numbers)
{
	int	i;

	i = 0;
	while (the_numbers->numbers[i])
	{
		free(the_numbers->numbers[i]);
		i++;
	}
	free(the_numbers->numbers);
}

void	freestack(t_data **my_stack)
{
	t_data	*tmp;

	if (my_stack)
	{
		while (*my_stack != NULL)
		{
			tmp = (*my_stack)->next;
			free(*my_stack);
			*my_stack = tmp;
		}
		*my_stack = NULL;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_free(t_data **stack_a, t_data **stack_b, char *line)
{
	ft_putstr2("Error\n");
	freestack(stack_a);
	freestack(stack_b);
	free(line);
}

void	free_exit(char **tmp, char *tmp2)
{
	int	j;

	ft_putstr2("Error\n");
	j = 0;
	while (tmp[j])
		free(tmp[j++]);
	free(tmp);
	free(tmp2);
	exit(1);
}
