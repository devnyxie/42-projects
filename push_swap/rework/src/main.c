/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:35:44 by tafanasi          #+#    #+#             */
/*   Updated: 2025/03/14 16:44:11 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_set *set)
{
	radix_sort(set);
}

int	main(int argc, char **argv)
{
	t_set	*set;

	set = NULL;
	if (argc < 2)
		return (-1);
	ft_check_args(argc, argv, set);
	set = init_set(argc, argv);
	if (is_sorted(set->a))
	{
		free_set(set);
		return (0);
	}
	sort_stack(set);
	free_set(set);
	return (0);
}
