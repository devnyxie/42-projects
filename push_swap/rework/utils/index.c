/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2025/03/14 16:28:57 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_node	*get_next_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;

	if (!stack || !stack->top)
	{
		return (NULL);
	}
	current = stack->top;
	min_node = NULL;
	while (current)
	{
		if (current->index == -1 && (!min_node
				|| current->value < min_node->value))
			min_node = current;
		current = current->next;
	}
	return (min_node);
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
