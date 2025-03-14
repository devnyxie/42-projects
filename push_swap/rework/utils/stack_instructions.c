/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:05:16 by tafanasi          #+#    #+#             */
/*   Updated: 2025/03/14 16:10:25 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rrr(t_set *set)
{
	if (stack_size(set->a) < 2 || stack_size(set->b) < 2)
		return (-1);
	reverseRotate(set->a);
	reverseRotate(set->b);
	ft_print("rrr\n");
	return (0);
}
