#include "push_swap.h"

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
} t_stack;

t_stack *init_stack(int argc, char **argv);
int is_sorted(t_stack *stack);
void sort_stack(t_stack **stack_a, t_stack **stack_b);
void radix_sort(t_stack **stack_a, t_stack **stack_b);
int stack_size(t_stack *stack);
int find_max_value(t_stack *stack);
void sort_two(t_stack **stack);
void sort_three(t_stack **stack);
void sort_five(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);
void pa(t_stack **stack_a, t_stack **stack_b);
void ra(t_stack **stack);
void free_stack(t_stack **stack);

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
        ra(stack);
}

void sort_three(t_stack **stack)
{
    int a = (*stack)->top->value;
    int b = (*stack)->top->next->value;
    int c = (*stack)->top->next->next->value;

    if (a > b && b < c && a < c) // Cas: 2, 1, 3
        sa(stack);
    else if (a > b && b > c) // Cas: 3, 2, 1
    {
        sa(stack);
        rra(stack);
    }
    else if (a > c && b < c) // Cas: 3, 1, 2
        ra(stack);
    else if (a < c && b > c) // Cas: 1, 3, 2
    {
        sa(stack);
        ra(stack);
    }
    else if (a < b && a > c) // Cas: 2, 3, 1
        rra(stack);
}


void pb(t_stack **stack_a, t_stack **stack_b)
{
    t_node *temp;
    if (!(*stack_a)->top)
        return;
    temp = (*stack_a)->top;
    (*stack_a)->top = temp->next;
    temp->next = (*stack_b)->top;
    (*stack_b)->top = temp;
    write("pb\n", 3);
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    t_node *temp;
    if (!(*stack_b)->top)
        return;
    temp = (*stack_b)->top;
    (*stack_b)->top = temp->next;
    temp->next = (*stack_a)->top;
    (*stack_a)->top = temp;
    write("pa\n", 3);
}

void ra(t_stack **stack)
{
    t_node *temp, *last;
    if (!(*stack)->top || !(*stack)->top->next)
        return;
    temp = (*stack)->top;
    (*stack)->top = temp->next;
    temp->next = NULL;
    last = (*stack)->top;
    while (last->next)
        last = last->next;
    last->next = temp;
    write("ra\n", 3);
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
                ra(stack_a);
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
