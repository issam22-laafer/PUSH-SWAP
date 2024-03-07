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
		ft_putstr("Eroor\n");
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
