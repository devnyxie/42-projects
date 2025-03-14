/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:05:48 by tafanasi          #+#    #+#             */
/*   Updated: 2025/03/14 16:24:47 by tafanasi         ###   ########.fr       */
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

void	error(t_set *set)
{
	ft_print("Error\n");
	free_set(set);
	exit(1);
}
