/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:05:48 by tafanasi          #+#    #+#             */
/*   Updated: 2025/03/17 18:34:51 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	get_distance(t_node *node, int index)
{
	t_node	*head;
	int		distance;

	distance = 0;
	head = node;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

// get min index from stack
int	get_min(t_stack *stack, int val)
{
	t_node	*head;
	int		min;

	head = stack->top;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	error(t_set *set)
{
	ft_print("Error\n");
	free_set(set);
	exit(1);
}
