
#include "checker_bonus.h"

int	check_lenght(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	if (ft_strlen(str + i) > 11)
		return (0);
	return (1);
}

int	if_number(char *str)
{
	int	i;

	i = 0;
	if (!check_lenght(str))
		return (0);
	if (ft_strlen(str) == 1 && (str[i] == '-' || str[i] == '+'))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	check_doubles(t_data **stack_a)
{
	t_data	*temp1;
	t_data	*temp2;

	temp1 = *stack_a;
	while (temp1)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->data == temp2->data)
			{
				ft_putstr("Eroor\n");
				freestack(stack_a);
				exit(1);
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}
