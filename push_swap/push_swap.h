#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
} t_stack;

// Stack operations
int stack_size(t_stack *stack);
int find_max_value(t_stack *stack);
t_stack *init_stack(int argc, char **argv);
void free_stack(t_stack **stack);

// Sorting algorithms
int is_sorted(t_stack *stack);
void sort_stack(t_stack **stack_a, t_stack **stack_b);
void radix_sort(t_stack **stack_a, t_stack **stack_b);
void sort_two(t_stack **stack);
void sort_three(t_stack **stack);
void sort_five(t_stack **stack_a, t_stack **stack_b);

// Stack manipulations
void pb(t_stack **stack_a, t_stack **stack_b);
void pa(t_stack **stack_a, t_stack **stack_b);
void ra(t_stack **stack);

// Utility functions
void ft_putstr_fd(char *s, int fd);
int ft_atoi(const char *str);

#endif
