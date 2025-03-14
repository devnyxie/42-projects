/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:04:27 by tafanasi          #+#    #+#             */
/*   Updated: 2025/03/14 16:04:29 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_node *top)
{
	t_node	*current;

	if (!top)
	{
		printf("Stack is empty\n");
		printf("------------------\n");
		return ;
	}
	printf("Stack Top\n");
	printf("------------------\n");
	current = top;
	while (current)
	{
		printf("│ %d\n", current->value);
		printf("│ ↓\n");
		current = current->next;
	}
	printf("------------------\n");
	printf("Stack Bottom\n");
}
