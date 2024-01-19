#include "monty.h"

int line_number;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    /* Open and read the Monty bytecode file */
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    /* Initialize stack */
    stack_t *stack = NULL;

    char opcode[256];
    int value;

    /* Read each line from the file */
    while (fscanf(file, "%s", opcode) != EOF)
    {
        if (strcmp(opcode, "push") == 0)
        {
            if (fscanf(file, "%d", &value) == EOF)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file);
                return (EXIT_FAILURE);
            }
            push(&stack, value);
        }
        else if (strcmp(opcode, "pint") == 0)
        {
            pint(&stack);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack);
        }
        else if (strcmp(opcode, "pop") == 0)
        {
            pop(&stack);
        }
        else if (strcmp(opcode, "swap") == 0)
        {
            swap(&stack);
        }
        else if (strcmp(opcode, "add") == 0)
        {
            add(&stack);
        }
        else if (strcmp(opcode, "nop") == 0)
        {
            nop(&stack);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            fclose(file);
            return (EXIT_FAILURE);
        }
    }

    /* Close the file */
    fclose(file);

    return (EXIT_SUCCESS);
}

