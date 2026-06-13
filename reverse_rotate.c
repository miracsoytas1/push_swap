/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miracsoytas <miracsoytas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:00:00 by miracsoytas       #+#    #+#             */
/*   Updated: 2026/02/03 18:00:00 by miracsoytas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_both(t_node **stack)
{
	t_node	*last;
	t_node	*new_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	new_last = last->prev;
	new_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_node **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	reverse_rotate_both(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	reverse_rotate_both(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	int	did_a;
	int	did_b;

	did_a = (stack_a && *stack_a && (*stack_a)->next);
	did_b = (stack_b && *stack_b && (*stack_b)->next);
	if (!did_a && !did_b)
		return ;
	if (did_a)
		reverse_rotate_both(stack_a);
	if (did_b)
		reverse_rotate_both(stack_b);
	write(1, "rrr\n", 4);
}
