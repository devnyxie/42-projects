/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:12:43 by tafanasi          #+#    #+#             */
/*   Updated: 2025/03/14 16:27:57 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rrb(t_set *set)
{
	if (reverse_rotate(set->b) == -1)
		return (-1);
	ft_print("rrb\n");
	return (0);
}
