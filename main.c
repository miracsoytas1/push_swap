/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miracsoytas <miracsoytas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:40:00 by miracsoytas       #+#    #+#             */
/*   Updated: 2026/02/03 20:40:00 by miracsoytas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	is_space(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	parse_arg(char *arg, t_node **stack_a)
{
	int	i;
	int	value;
	int	len;

	i = 0;
	len = 0;
	while (arg[i])
	{
		while (arg[i] && is_space(arg[i]))
			i++;
		if (!arg[i])
			break ;
		if (!parse_number(&arg[i], &value, &len))
			return (0);
		if (arg[i + len] && !is_space(arg[i + len]))
			return (0);
		if (check_duplicate(*stack_a, value))
			return (0);
		if (!add_back(stack_a, value))
			return (0);
		i += len;
	}
	return (len != 0);
}

static int	parse_args(int ac, char **av, t_node **stack_a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!parse_arg(av[i], stack_a))
		{
			free_stack(stack_a);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_args(ac, av, &stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!is_sorted(stack_a))
		turk_algorithm(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
