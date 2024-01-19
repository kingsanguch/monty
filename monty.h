#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>

/* Data structure for stack node */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
} stack_t;

/* Function prototypes */
void push(stack_t **stack, int value);
void pall(stack_t **stack);
void pint(stack_t **stack);
void pop(stack_t **stack);
void swap(stack_t **stack);
void add(stack_t **stack);
void nop(stack_t **stack);



#endif /* MONTY_H */
