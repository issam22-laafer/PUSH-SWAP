
#include "checker_bonus.h"
#include "./get-next-line/get_next_line.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void instruction(t_data **stack_a, t_data **stack_b)
{
        char *line;

        line  = get_next_line(0);
        while (line)
        {
                if (ft_strcmp(line, "sa\n") == 0)
                        swap_a(stack_a);
                else if (ft_strcmp(line, "sb\n") == 0)
                        swap_b(stack_b);
                else if (ft_strcmp(line, "ss\n") == 0)
                        ss(stack_a,stack_b);
                else if (ft_strcmp(line, "pa\n") == 0)
                        push_a(stack_b,stack_a);
                else if (ft_strcmp(line, "pb\n") == 0)
                        push_b(stack_a,stack_b);
                else if (ft_strcmp(line, "ra\n") == 0)
                        rotate_a(stack_a);
                else if (ft_strcmp(line, "rb\n") == 0)
                        rotate_b(stack_b);
                else if (ft_strcmp(line, "rr\n") == 0)
                        rr(stack_a,stack_b);
                else if (ft_strcmp(line, "rra\n") == 0)
                        reverse_rotate_a(stack_a);
                else if (ft_strcmp(line, "rrb\n") == 0)
                        reverse_rotate_b(stack_b);
                else if (ft_strcmp(line, "rrr\n") == 0)
                        rrr(stack_a,stack_b);
                else
                {
                        ft_putstr("Error\n");
                        exit(1);
                }
                free(line);
                line = get_next_line(0);
        }
        free(line);
}