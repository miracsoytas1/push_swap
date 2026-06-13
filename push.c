/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miracsoytas <miracsoytas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:00:00 by miracsoytas       #+#    #+#             */
/*   Updated: 2026/02/03 18:00:00 by miracsoytas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_top(t_node **dst, t_node **src)
{
	t_node	*node;

	if (!src || !*src)
		return ;
	node = *src;
	*src = node->next;
	if (*src)
		(*src)->prev = NULL;
	node->next = *dst;
	if (*dst)
		(*dst)->prev = node;
	node->prev = NULL;
	*dst = node;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (!stack_b || !*stack_b)
		return ;
	move_top(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !*stack_a)
		return ;
	move_top(stack_b, stack_a);
	write(1, "pb\n", 3);
}
