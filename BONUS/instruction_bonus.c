/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:07:22 by lissam            #+#    #+#             */
/*   Updated: 2024/03/09 21:16:04 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get-next-line/get_next_line.h"
#include "checker_bonus.h"
#include "fcntl.h"
void	instruction_s(t_data **stack_a, t_data **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap_a(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap_b(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b);
}

void	instruction_p(t_data **stack_a, t_data **stack_b, char *line)
{
	if (ft_strcmp(line, "pa\n") == 0)
		push_a(stack_b, stack_a);
	else if (ft_strcmp(line, "pb\n") == 0)
		push_b(stack_a, stack_b);
}

void	instruction_r(t_data **stack_a, t_data **stack_b, char *line)
{
	if (ft_strcmp(line, "ra\n") == 0)
		rotate_a(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate_b(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b);
}

void	instruction_rr(t_data **stack_a, t_data **stack_b, char *line)
{
	if (ft_strcmp(line, "rra\n") == 0)
		reverse_rotate_a(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_rotate_b(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b);
}

void	instruction(t_data **stack_a, t_data **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, "sa\n") == 0 || ft_strcmp(line, "sb\n") == 0
			|| ft_strcmp(line, "ss\n") == 0)
			instruction_s(stack_a, stack_b, line);
		else if (ft_strcmp(line, "pa\n") == 0 || ft_strcmp(line, "pb\n") == 0)
			instruction_p(stack_a, stack_b, line);
		else if (ft_strcmp(line, "ra\n") == 0 || ft_strcmp(line, "rb\n") == 0
			|| ft_strcmp(line, "rr\n") == 0)
			instruction_r(stack_a, stack_b, line);
		else if (ft_strcmp(line, "rra\n") == 0 || ft_strcmp(line, "rrb\n") == 0
			|| ft_strcmp(line, "rrr\n") == 0)
			instruction_rr(stack_a, stack_b, line);
		else
		{
			ft_free(stack_a, stack_b);
			free(line);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}
