/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:45:55 by lissam            #+#    #+#             */
/*   Updated: 2024/02/29 11:17:19 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	free_and_exit(t_numbers *the_numbers, t_data **stack_a)
{
	int	i;

	i = 0;
	while (the_numbers->numbers[i])
		free(the_numbers->numbers[i++]);
	free(the_numbers->numbers);
	freestack(stack_a);
	exit(1);
}

long long	result(char *str, int i)
{
	int			r;
	long long	d;

	r = 0;
	d = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		d = (d * 10) + (str[i] - '0');
		i++;
	}
	return (d);
}

int	ft_atoi(char *str, t_numbers *the_numbers, t_data **stack_a)
{
	int			i;
	int			s;
	long long	d;

	i = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	d = result(str, i) * s;
	if (d > INT_MAX || d < INT_MIN)
	{
		ft_putstr("Eroor\n");
		free_and_exit(the_numbers, stack_a);
	}
	return (result(str, i) * s);
}
