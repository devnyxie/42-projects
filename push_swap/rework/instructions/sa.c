/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:12:32 by tafanasi          #+#    #+#             */
/*   Updated: 2025/03/14 16:12:34 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sa(t_set *set)
{
	if (swap(set->a) == -1)
		return (-1);
	ft_print("sa\n");
	return (0);
}
