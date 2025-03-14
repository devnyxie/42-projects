#include "../includes/push_swap.h"

void	free_args(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

void free_stack(t_stack *stack){
	t_node *current = stack->top;
	t_node *next;

	while(current)
    {
		next = current->next;
		free(current);
		current = next;		
	}
	free(stack);
}

void free_set(t_set *set){
	if(set){
		if(set->a)
			free_stack(set->a);
		if(set->b)
			free_stack(set->b);
		free(set);
	}
}
