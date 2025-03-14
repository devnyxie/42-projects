/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafanasi <tafanasi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:59:15 by tafanasi          #+#    #+#             */
/*   Updated: 2025/03/14 16:34:35 by tafanasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
}					t_stack;

typedef struct s_set
{
	t_stack			*a;
	t_stack			*b;
}					t_set;

// utils.c
void				error(t_set *set);
// mem.c
void				free_stack(t_stack *stack);
void				free_set(t_set *set);
void				free_args(char **str);
// ft_print.c (to be reviewed)
void				ft_print(const char *str);
// stack.c
void				add(t_stack *stack, int value);
void				add_end(t_stack *stack, int value);
t_set				*init_set(int argc, char **argv);
int					is_sorted(t_stack *stack);
// index.c
void				index_stack(t_stack *a);
// check_args.c
void				ft_check_args(int argc, char **argv, t_set *set);
// debug.c
void				print_stack(t_node *top);
// instructions.c
int					stack_size(t_stack *stack);
int					ra(t_set *set);
int					pb(t_set *set);
int					pa(t_set *set);
// radix.c
void				radix_sort(t_set *set);

// stack_utils.c
int					stack_size(t_stack *stack);
int					swap(t_stack *stack);
int					push(t_stack *to, t_stack *from);
int					rotate(t_stack *stack);
int					reverse_rotate(t_stack *stack);

// stack_instructions.c
int					sa(t_set *set);
int					sb(t_set *set);
int					ss(t_set *set);
int					pa(t_set *set);
int					pb(t_set *set);
int					ra(t_set *set);
int					rb(t_set *set);
int					rr(t_set *set);
int					rra(t_set *set);
int					rrb(t_set *set);
int					rrr(t_set *set);

#endif
