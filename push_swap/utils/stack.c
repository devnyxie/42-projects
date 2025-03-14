/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:24:52 by tafanasi          #+#    #+#             */
/*   Updated: 2025/03/14 16:28:43 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->index = -1;
	new_node->next = stack->top;
	stack->top = new_node;
}

void	add_end(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	if (!stack->top)
	{
		stack->top = new_node;
	}
	else
	{
		current = stack->top;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

static void	fill_stack(char **argv, int argc, t_stack *a)
{
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		add_end(a, ft_atoi(args[i]));
		i++;
	}
	index_stack(a);
	if (argc == 2)
		free_args(args);
}

t_set	*init_set(int argc, char **argv)
{
	t_set	*set;

	set = malloc(sizeof(t_set));
	if (!set)
		error(set);
	set->a = malloc(sizeof(t_stack));
	set->b = malloc(sizeof(t_stack));
	if (!set->a || !set->b)
		error(set);
	set->a->top = NULL;
	set->b->top = NULL;
	fill_stack(argv, argc, set->a);
	return (set);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
