/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:30:31 by lissam            #+#    #+#             */
/*   Updated: 2024/03/05 21:41:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
