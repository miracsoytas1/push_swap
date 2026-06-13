/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miracsoytas <miracsoytas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:00:00 by miracsoytas       #+#    #+#             */
/*   Updated: 2026/02/03 19:00:00 by miracsoytas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top_b(t_node **stack, int pos)
{
	int	size;

	size = stack_size(*stack);
	if (pos <= size / 2)
		while (pos-- > 0)
			rb(stack);
	else
		while (pos++ < size)
			rrb(stack);
}

void	push_chunks(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	chunk;
	int	i;

	size = stack_size(*stack_a);
	chunk = 45;
	if (size <= 100)
		chunk = 15;
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->value <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->value <= i + chunk)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	push_back(t_node **stack_a, t_node **stack_b)
{
	int	max;
	int	pos;

	while (*stack_b)
	{
		max = find_extreme(*stack_b, 1);
		pos = find_position(*stack_b, max);
		rotate_to_top_b(stack_b, pos);
		pa(stack_a, stack_b);
	}
}

void	slow_sort(t_node **stack_a, t_node **stack_b)
{
	int	min;
	int	pos;

	while (stack_size(*stack_a) > 3)
	{
		min = find_extreme(*stack_a, 0);
		pos = find_position(*stack_a, min);
		if (pos <= stack_size(*stack_a) / 2)
			while (pos-- > 0)
				ra(stack_a);
		else
			while (pos++ < stack_size(*stack_a))
				rra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		min = find_extreme(*stack_b, 1);
		pos = find_position(*stack_b, min);
		rotate_to_top_b(stack_b, pos);
		pa(stack_a, stack_b);
	}
}

void	sort_three(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}
