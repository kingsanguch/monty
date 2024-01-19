#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the beginning of the stack
 *
 * Description: The top two elements of the stack are swapped.
 * If the stack contains less than two elements, print an error message
 * and exit with status EXIT_FAILURE.
 */
void swap(stack_t **stack)
{
    stack_t *temp;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    (*stack)->next = temp->next;
    if (temp->next)
        temp->next->prev = *stack;

    temp->prev = NULL;
    temp->next = *stack;
    (*stack)->prev = temp;
    *stack = temp;
}
