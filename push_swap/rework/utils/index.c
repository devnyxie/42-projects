/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2025/03/12 20:41:14 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static Node* get_next_min(Stack *stack) {
    if (!stack || !stack->top) {
        return NULL;
    }

    Node *current = stack->top;
    Node *minNode = NULL;
    
    while (current) {
        if (current->index == -1 && (!minNode || current->value < minNode->value))
            minNode = current;
        current = current->next;
    }
    
    return minNode;
}


void	index_stack(Stack *a)
{
	Node	*head;
	int		index;

	index = 0;
	head = get_next_min(a);
	while (head)
	{
		head->index = index++;
		head = get_next_min(a);
	}
}

