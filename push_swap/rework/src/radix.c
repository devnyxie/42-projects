#include "../includes/push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	t_node	*head;

	head = stack->top;
	int max, max_bits;
	if (!head)
		return (0);
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_set *set)
{
	t_node	*head_a;

	int i, j, size, max_bits;
	i = 0;
	size = stack_size(set->a);
	max_bits = get_max_bits(set->a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = set->a->top;
			if (((head_a->index >> i) & 1) == 1)
				ra(set); // rotate stack A
			else
				pb(set); // push from A to B
		}
		while (stack_size(set->b) != 0)
			pa(set); // push back from B to A
		i++;
	}
}
