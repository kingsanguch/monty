#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Pointer to the top of the stack.
 */
void pint(stack_t **stack)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
