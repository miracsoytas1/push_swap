/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miracsoytas <miracsoytas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:40:00 by miracsoytas       #+#    #+#             */
/*   Updated: 2026/02/03 20:40:00 by miracsoytas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

t_node	*new_node(int value);
int		add_back(t_node **stack, int value);
void	free_stack(t_node **stack);
int		stack_size(t_node *stack);
int		find_position(t_node *stack, int value);
int		is_sorted(t_node *stack);
int		find_extreme(t_node *stack, int is_max);
int		parse_number(const char *str, int *out, int *len);
int		handle_small(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	swap_top(t_node **stack);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rotate_both(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_both(t_node **stack);
void	sort_three(t_node **stack_a);
void	push_chunks(t_node **stack_a, t_node **stack_b);
void	push_back(t_node **stack_a, t_node **stack_b);
void	slow_sort(t_node **stack_a, t_node **stack_b);
int		index_stack(t_node *stack);
void	turk_algorithm(t_node **stack_a, t_node **stack_b);

#endif
