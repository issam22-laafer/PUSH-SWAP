#include "push_swap.h"



void closest_bigger(int nb, int *target, t_data **stack_a)
{
    t_data	*tmp_a;

	tmp_a = *stack_a;
	*target = find_first_target_b(nb, stack_a);
	while (tmp_a)
	{
		if (tmp_a->data > nb && tmp_a->data < *target)
			*target = tmp_a->data;
		tmp_a = tmp_a->next;
	}
}

void	target_b_push(t_data **stack_b, t_data **stack_a)
{
    t_data *tmp_b;
    int target;

    tmp_b = *stack_b;
    while(tmp_b)
    {
        if (find_first_target_b(tmp_b->data, stack_a) == the_small_n(stack_a))
			target = the_small_n(stack_b);
        else
        {
			closest_bigger(tmp_b->data, &target, stack_a);
        }
        printf("The target of %d, is ===> %d\n",tmp_b->data,target);
		tmp_b = tmp_b->next;
    }
}

