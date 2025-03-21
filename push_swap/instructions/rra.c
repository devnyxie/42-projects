/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:13:22 by tafanasi          #+#    #+#             */
/*   Updated: 2025/03/14 16:27:54 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rra(t_set *set)
{
	if (reverse_rotate(set->a) == -1)
		return (-1);
	ft_print("rra\n");
	return (0);
}
