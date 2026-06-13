#include "push_swap.h"

void    sa(t_node **stack)
{
    t_node  *first;
    t_node  *second;

    if (!*stack || (*stack)-> next == NULL)
        return ;

    first = *stack;
    second = first -> next;

    first -> next = second -> next;
    if (first -> next)
        first -> next -> prev = first;

    second -> next = first;

    first -> prev = second;
    second -> prev = NULL;

    *stack = second;
}

void    sb(t_node **stack)
{
    t_node  *first;
    t_node  *second;

    if (!*stack || (*stack)-> next == NULL)
        return ;

    first = *stack;
    second = first -> next;

    first -> next = second -> next;
    if (first -> next)
        first -> next -> prev = first;

    second -> next = first;

    first -> prev = second;
    second -> prev = NULL;

    *stack = second;
}

void    swap_top(t_node **stack)
{
    t_node  *first;
    t_node  *second;

    if (!*stack || (*stack)-> next == NULL)
        return ;

    first = *stack;
    second = first -> next;

    first -> next = second -> next;
    if (first -> next)
        first -> next -> prev = first;

    second -> next = first;

    first -> prev = second;
    second -> prev = NULL;

    *stack = second;
}

void    ss(t_node **stack_a, t_node **stack_b)
{
    swap_top(stack_a);
    swap_top(stack_b);
}