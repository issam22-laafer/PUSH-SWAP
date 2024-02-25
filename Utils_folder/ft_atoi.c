/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:45:55 by lissam            #+#    #+#             */
/*   Updated: 2024/02/25 17:18:42 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	r;
	long long d;

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
	r = 0;
	d = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		d = (d * 10) + (str[i] - '0');
		i++;
	}
	d = d * s;
	if(d > INT_MAX || d < INT_MIN)
	{
		ft_putstr("Eroor");
		exit(1);
	}
	return (r * s);
}
