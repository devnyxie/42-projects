#include "../includes/push_swap.h"

// sa: swap first two elements of stack A
int	sa(t_set *set)
{
	if (swap(set->a) == -1)
		return (-1);
	ft_print("sa\n");
	return (0);
}

// sb: swap first two elements of stack B
int	sb(t_set *set)
{
	if (swap(set->b) == -1)
		return (-1);
	ft_print("sb\n");
	return (0);
}

// ss: swap both stacks simultaneously
int	ss(t_set *set)
{
	if (stack_size(set->a) < 2 || stack_size(set->b) < 2)
		return (-1);
	swap(set->a);
	swap(set->b);
	ft_print("ss\n");
	return (0);
}

// pa: push from stack B to stack A
int	pa(t_set *set)
{
	if (push(set->a, set->b) == -1)
		return (-1);
	ft_print("pa\n");
	return (0);
}

// pb: push from stack A to stack B
int	pb(t_set *set)
{
	if (push(set->b, set->a) == -1)
		return (-1);
	ft_print("pb\n");
	return 0;
}

// ra: rotate stack A
int	ra(t_set *set)
{
	if (rotate(set->a) == -1)
		return -1;
	ft_print("ra\n");
	return 0;
}

// rb: rotate stack B
int	rb(t_set *set)
{
	if (rotate(set->b) == -1)
		return -1;
	ft_print("rb\n");
	return 0;
}

// rr: rotate both stacks simultaneously
int	rr(t_set *set)
{
	if (stack_size(set->a) < 2 || stack_size(set->b) < 2)
		return -1;
	rotate(set->a);
	rotate(set->b);
	ft_print("rr\n");
	return 0;
}

// rra: reverse rotate stack A
int	rra(t_set *set)
{
	if (reverseRotate(set->a) == -1)
		return -1;
	ft_print("rra\n");
	return 0;
}

// rrb: reverse rotate stack B
int	rrb(t_set *set)
{
	if (reverseRotate(set->b) == -1)
		return -1;
	ft_print("rrb\n");
	return 0;
}

// rrr: reverse rotate both stacks simultaneously
int	rrr(t_set *set)
{
	if (stack_size(set->a) < 2 || stack_size(set->b) < 2)
		return -1;
	reverseRotate(set->a);
	reverseRotate(set->b);
	ft_print("rrr\n");
	return 0;
}
