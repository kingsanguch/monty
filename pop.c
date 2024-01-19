#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 *
 * Description: If the stack is empty, print an error message.
 */
void pop(stack_t **stack)
{
	stack_t *temp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	if (temp->prev)
	{
		*stack = temp->prev;
		(*stack)->n = temp->n;
		free(temp);
	}
	else
	{
		free(temp);
		*stack = NULL;
	}
}
