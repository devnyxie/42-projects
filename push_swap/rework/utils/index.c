/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2025/03/14 16:04:52 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*get_next_min(t_stack *stack)
{
	t_node	*current;
	t_node	*minNode;

	if (!stack || !stack->top)
	{
		return (NULL);
	}
	current = stack->top;
	minNode = NULL;
	while (current)
	{
		if (current->index == -1 && (!minNode
				|| current->value < minNode->value))
			minNode = current;
		current = current->next;
	}
	return (minNode);
}

void	index_stack(t_stack *a)
{
	t_node	*head;
	int		index;

	index = 0;
	head = get_next_min(a);
	while (head)
	{
		head->index = index++;
		head = get_next_min(a);
	}
}
