/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:23:11 by lissam            #+#    #+#             */
/*   Updated: 2024/03/01 09:22:41 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

int	min_index(int i, int j)
{
	if (i >= j)
		return (j);
	return (i);
}

int	max_index(int i, int j)
{
	if (i >= j)
		return (i);
	return (j);
}
