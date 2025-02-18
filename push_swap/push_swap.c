#include "push_swap.h"

int stack_size(t_stack *stack)
{
    int size = 0;
    t_node *current = stack->top;
    while (current)
    {
        size++;
        current = current->next;
    }
    return size;
}

int find_max_value(t_stack *stack)
{
    int max = stack->top->value;
    t_node *current = stack->top;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return max;
}

void sort_two(t_stack **stack)
{
    if ((*stack)->top->value > (*stack)->top->next->value)
        ra(stack, 0);
}

void sort_three(t_stack **stack)
{
    int a = (*stack)->top->value;
    int b = (*stack)->top->next->value;
    int c = (*stack)->top->next->next->value;

    if (a > b && b < c && a < c) // Cas: 2, 1, 3
        sa(stack, 0);
    else if (a > b && b > c) // Cas: 3, 2, 1
    {
        sa(stack, 0);
        rra(stack, 0);
    }
    else if (a > c && b < c) // Cas: 3, 1, 2
        ra(stack, 0);
    else if (a < c && b > c) // Cas: 1, 3, 2
    {
        sa(stack, 0);
        ra(stack, 0);
    }
    else if (a < b && a > c) // Cas: 2, 3, 1
        rra(stack, 0);
}

void free_stack(t_stack **stack)
{
    t_node *current = (*stack)->top;
    t_node *next;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(*stack);
    *stack = NULL;
}

t_stack *init_stack(int argc, char **argv)
{
    t_stack *stack;
    int i;
    
    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    i = 1;
    while (i < argc)
    {
        t_node *new_node = malloc(sizeof(t_node));
        if (!new_node)
            return (NULL);
        new_node->value = ft_atoi(argv[i]);
        new_node->next = stack->top;
        stack->top = new_node;
        i++;
    }
    return (stack);
}

int is_sorted(t_stack *stack)
{
    t_node *current;
    
    if (!stack || !stack->top)
        return (1);
    current = stack->top;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int max_bits = 0;
    int size = stack_size(*stack_a);
    int max_value = find_max_value(*stack_a);
    t_node *current;
    
    while ((max_value >> max_bits) != 0)
        max_bits++;
    
    for (int i = 0; i < max_bits; i++)
    {
        int count = size;
        while (count--)
        {
            current = (*stack_a)->top;
            if (((current->value >> i) & 1) == 0)
                pb(stack_a, stack_b);
            else
                ra(stack_a, 0);
        }
        while (*stack_b)
            pa(stack_a, stack_b);
    }
}

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
    int size = stack_size(*stack_a);
    
    if (size == 2)
        sort_two(stack_a);
    else if (size == 3)
        sort_three(stack_a);
    else if (size <= 5)
        sort_five(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    
    if (argc < 2)
        return (0);
    
    stack_a = init_stack(argc, argv);
    stack_b = init_stack(0, NULL); // Stack B démarre vide
    
    if (!stack_a || !stack_b)
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    
    if (!is_sorted(stack_a))
        sort_stack(&stack_a, &stack_b);
    
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
