#include "checker_bonus.h"

void	ss(t_data **stack_a, t_data **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	rr(t_data **stack_a, t_data **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	rrr(t_data **stack_a, t_data **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
