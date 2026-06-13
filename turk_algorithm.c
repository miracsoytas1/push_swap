#include "push_swap.h"

int stack_size(t_node *stack)
{
    int count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}

int find_min(t_node *stack)
{
    int min;

    min = stack->value;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return (min);
}

int find_position(t_node *stack, int value)
{
    int pos = 0;

    while (stack)
    {
        if (stack->value == value)
            return (pos);
        pos++;
        stack = stack->next;
    }
    return (-1);
}

void rotate_to_top(t_node **stack, int pos)
{
    int size;

    size = stack_size(*stack);
    if (pos <= size / 2)
    {
        while (pos--)
            ra(stack);
    }
    else
    {
        while (pos++ < size)
            rra(stack);
    }
}

void turk_algorithm(t_node **stack_a, t_node **stack_b)
{
    int min;
    int pos;

    while (stack_size(*stack_a) > 3)
    {
        min = find_min(*stack_a);
        pos = find_position(*stack_a, min);
        rotate_to_top(stack_a, pos);
        pb(stack_a, stack_b);
    }
    sort_three(stack_a);
    while (*stack_b)
        pa(stack_a, stack_b);
}

