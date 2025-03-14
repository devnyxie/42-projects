#include "../includes/push_swap.h"

// Helper function: Count nodes in a stack
int	stack_size(t_stack *stack)
{
	int		count;
	t_node	*curr;

	count = 0;
	curr = stack->top;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

// Helper function: Get the last node in a stack
static t_node	*stack_last(t_stack *stack)
{
	t_node	*curr;

	curr = stack->top;
	if (!curr)
		return (NULL);
	while (curr->next)
		curr = curr->next;
	return (curr);
}

// Swap the first two elements of a stack
int	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		tmp_value;
	int		tmp_index;

	if (stack_size(stack) < 2)
		return (-1);
	first = stack->top;
	second = first->next;
	// Swap value and index
	tmp_value = first->value;
	tmp_index = first->index;
	first->value = second->value;
	first->index = second->index;
	second->value = tmp_value;
	second->index = tmp_index;
	return (0);
}

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

// Push: takes the top element from 'from' and puts it on 'to'
int	push(t_stack *to, t_stack *from)
{
	t_node	*node;

	if (!from->top)
		return (-1);
	node = from->top;
	from->top = node->next;
	node->next = to->top;
	to->top = node;
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

// Rotate: shift up all elements; first becomes last
int	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack_size(stack) < 2)
		return -1;
	first = stack->top;
	last = stack_last(stack);
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
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

// Reverse rotate: shift down all elements; last becomes first
int	reverseRotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*curr;

	if (stack_size(stack) < 2)
		return -1;
	prev = NULL;
	curr = stack->top;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	// 'curr' is the last element, 'prev' is second-to-last
	if (prev)
		prev->next = NULL;
	curr->next = stack->top;
	stack->top = curr;
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
