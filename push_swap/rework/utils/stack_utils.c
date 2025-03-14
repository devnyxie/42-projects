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
