/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:18:34 by tafanasi          #+#    #+#             */
/*   Updated: 2025/03/17 18:29:19 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	handle_min_case(t_set *set, t_node *head, int next_min)
{
	if (head->index == next_min)
	{
		if (head->next->index == next_min)
			sa(set);
		else
			rra(set);
	}
	else
	{
		if (head->next->index == next_min)
			ra(set);
		else
		{
			sa(set);
			rra(set);
		}
	}
}

static void	sort_3(t_set *set)
{
	t_node	*head;
	int		min;
	int		next_min;

	head = set->a->top;
	min = get_min(set->a, -1);
	next_min = get_min(set->a, min);
	if (is_sorted(set->a))
		return ;
	if (head->index == min && head->next->index != next_min)
	{
		ra(set);
		sa(set);
		rra(set);
	}
	else
		handle_min_case(set, head, next_min);
}

static void	sort_4(t_set *set)
{
	int	distance;

	if (is_sorted(set->a))
		return ;
	distance = get_distance(set->a->top, get_min(set->a, -1));
	if (distance == 1)
		ra(set);
	else if (distance == 2)
	{
		ra(set);
		ra(set);
	}
	else if (distance == 3)
		rra(set);
	if (is_sorted(set->a))
		return ;
	pb(set);
	sort_3(set);
	pa(set);
}

void	sort_5(t_set *set)
{
	int	distance;

	distance = get_distance(set->a->top, get_min(set->a, -1));
	if (distance == 1)
		ra(set);
	else if (distance == 2)
	{
		ra(set);
		ra(set);
	}
	else if (distance == 3)
	{
		rra(set);
		rra(set);
	}
	else if (distance == 4)
		rra(set);
	if (is_sorted(set->a))
		return ;
	pb(set);
	sort_4(set);
	pa(set);
}

void	simple_sort(t_set *set)
{
	int	size;

	if (is_sorted(set->a) || stack_size(set->a) == 0 || stack_size(set->a) == 1)
		return ;
	size = stack_size(set->a);
	if (size == 2)
		sa(set);
	else if (size == 3)
		sort_3(set);
	else if (size == 4)
		sort_4(set);
	else if (size == 5)
		sort_5(set);
}
