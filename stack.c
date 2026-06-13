/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miracsoytas <miracsoytas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:40:00 by miracsoytas       #+#    #+#             */
/*   Updated: 2026/02/03 20:40:00 by miracsoytas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	add_back(t_node **stack, int value)
{
	t_node	*last;
	t_node	*new;

	new = new_node(value);
	if (!new)
		return (0);
	if (!stack)
		return (0);
	if (!*stack)
	{
		*stack = new;
		return (1);
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
	return (1);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while (stack && *stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	find_position(t_node *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

int	find_extreme(t_node *stack, int is_max)
{
	int	extreme;

	extreme = stack->value;
	stack = stack->next;
	while (stack)
	{
		if ((is_max && stack->value > extreme)
			|| (!is_max && stack->value < extreme))
			extreme = stack->value;
		stack = stack->next;
	}
	return (extreme);
}
