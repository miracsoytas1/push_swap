/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miracsoytas <miracsoytas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:00:00 by miracsoytas       #+#    #+#             */
/*   Updated: 2026/02/03 20:00:00 by miracsoytas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

static int	can_add_digit(long num, long limit, int digit)
{
	if (num > limit / 10)
		return (0);
	if (num == limit / 10 && digit > limit % 10)
		return (0);
	return (1);
}

int	parse_number(const char *str, int *out, int *len)
{
	long	num;
	long	sign;
	long	limit;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	limit = (long)INT_MAX + (sign == -1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (!can_add_digit(num, limit, str[i] - '0'))
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	*out = (int)(num * sign);
	*len = i;
	return (1);
}

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	handle_small(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size <= 1)
		return (1);
	if (size == 2)
	{
		if (!is_sorted(*stack_a))
			sa(stack_a);
		return (1);
	}
	if (size == 3)
	{
		sort_three(stack_a);
		return (1);
	}
	if (size <= 5)
	{
		slow_sort(stack_a, stack_b);
		return (1);
	}
	return (0);
}
