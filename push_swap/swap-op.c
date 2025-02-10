#include "push_swap.h"
// Swap the first two elements of stack A
void sa(t_stack **stack_a)
{
    t_node *first, *second;
    if (!(*stack_a)->top || !(*stack_a)->top->next)
        return;
    first = (*stack_a)->top;
    second = first->next;
    first->next = second->next;
    second->next = first;
    (*stack_a)->top = second;
}

// Swap the first two elements of stack B
void sb(t_stack **stack_b)
{
    t_node *first, *second;
    if (!(*stack_b)->top || !(*stack_b)->top->next)
        return;
    first = (*stack_b)->top;
    second = first->next;
    first->next = second->next;
    second->next = first;
    (*stack_b)->top = second;
}

// Swap the first two elements of both stacks A and B
void ss(t_stack **stack_a, t_stack **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

// Push the first element of stack A onto stack B
void pb(t_stack **stack_a, t_stack **stack_b)
{
    t_node *temp;
    if (!(*stack_a)->top)
        return;
    temp = (*stack_a)->top;
    (*stack_a)->top = temp->next;
    temp->next = (*stack_b)->top;
    (*stack_b)->top = temp;
}

// Push the first element of stack B onto stack A
void pa(t_stack **stack_a, t_stack **stack_b)
{
    t_node *temp;
    if (!(*stack_b)->top)
        return;
    temp = (*stack_b)->top;
    (*stack_b)->top = temp->next;
    temp->next = (*stack_a)->top;
    (*stack_a)->top = temp;
}

// Rotate stack A (first element becomes last)
void ra(t_stack **stack_a)
{
    t_node *temp, *last;
    if (!(*stack_a)->top || !(*stack_a)->top->next)
        return;
    temp = (*stack_a)->top;
    (*stack_a)->top = temp->next;
    temp->next = NULL;
    last = (*stack_a)->top;
    while (last->next)
        last = last->next;
    last->next = temp;
}

// Rotate stack B (first element becomes last)
void rb(t_stack **stack_b)
{
    t_node *temp, *last;
    if (!(*stack_b)->top || !(*stack_b)->top->next)
        return;
    temp = (*stack_b)->top;
    (*stack_b)->top = temp->next;
    temp->next = NULL;
    last = (*stack_b)->top;
    while (last->next)
        last = last->next;
    last->next = temp;
}

// Rotate both stacks A and B
void rr(t_stack **stack_a, t_stack **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

// Reverse rotate stack A (last element becomes first)
void rra(t_stack **stack_a)
{
    t_node *prev, *last;
    if (!(*stack_a)->top || !(*stack_a)->top->next)
        return;
    prev = NULL;
    last = (*stack_a)->top;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = (*stack_a)->top;
    (*stack_a)->top = last;
}

// Reverse rotate stack B (last element becomes first)
void rrb(t_stack **stack_b)
{
    t_node *prev, *last;
    if (!(*stack_b)->top || !(*stack_b)->top->next)
        return;
    prev = NULL;
    last = (*stack_b)->top;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = (*stack_b)->top;
    (*stack_b)->top = last;
}

// Reverse rotate both stacks A and B
void rrr(t_stack **stack_a, t_stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}
