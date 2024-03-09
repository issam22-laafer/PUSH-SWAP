/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:07:14 by lissam            #+#    #+#             */
/*   Updated: 2024/03/09 21:46:50 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	insert_back(t_data **head, int nb)
{
	t_data	*node;
	t_data	*tmp;

	node = malloc(sizeof(t_data));
	node->data = nb;
	node->next = NULL;
	if (*head == NULL)
		*head = node;
	else
	{
		tmp = *head;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
	}
}

int	count_nodes(t_data **stack)
{
	t_data	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	check_n_args(int ac, char **av)
{
	if (ac == 1)
	{
		exit(1);
	}
	if (!av[1][0])
	{
		ft_putstr2("Error\n");
		exit(1);
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
