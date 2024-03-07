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
