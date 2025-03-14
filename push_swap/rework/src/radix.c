/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:00:56 by tafanasi          #+#    #+#             */
/*   Updated: 2025/03/14 16:03:31 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	t_node	*head;
	int		max;
	int		max_bits;

	head = stack->top;
	if (!head)
		return (0);
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_set *set)
{
	t_node	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	size = stack_size(set->a);
	max_bits = get_max_bits(set->a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = set->a->top;
			if (((head_a->index >> i) & 1) == 1)
				ra(set);
			else
				pb(set);
		}
		while (stack_size(set->b) != 0)
			pa(set);
		i++;
	}
}
