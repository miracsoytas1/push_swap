#include "push_swap.h"

void    ra(t_node **stack_a)
{
    t_node  *first;
    t_node  *last;

    if (!*stack_a || (*stack_a)-> next == NULL)
        return ;

    first = *stack_a;
    *stack_a = first -> next;
    (*stack_a)-> prev = NULL;

    last = *stack_a;
    while (last -> next)
        last = last -> next;

    last -> next = first;
    first -> prev = last;
    first -> next = NULL;
}

void    rb(t_node **stack_b)
{
    t_node  *first;
    t_node  *last;

    if (!*stack_b || (*stack_b)-> next == NULL)
        return ;

    first = *stack_b;
    *stack_b = first -> next;
    (*stack_b)-> prev = NULL;

    last = *stack_b;
    while (last -> next)
        last = last -> next;

    last -> next = first;
    first -> prev = last;
    first -> next = NULL;
}

void    rotate_both(t_node **stack)
{
    t_node  *first;
    t_node  *last;

    if (!*stack || (*stack)-> next == NULL)
        return ;

    first = *stack;
    *stack = first -> next;
    (*stack)-> prev = NULL;

    last = *stack;
    while (last -> next)
        last = last -> next;

    last -> next = first;
    first -> prev = last;
    first -> next = NULL;
}

void    rr(t_node **stack_a, t_node **stack_b)
{
    rotate_both(stack_a);
    rotate_both(stack_b);
}