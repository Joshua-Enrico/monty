#include "monty.h"

/**
 * 
 * 
 * 
 * 
 * 
 */
void check_if_op_match(char *op, stack_t **stack,unsigned int line_number)
{
    size_t i;
    instruction_t valid_ops[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {NULL, NULL}
    };

    for (i = 0; valid_ops[i].opcode != NULL; i++)
    {
        if (strcmp(valid_ops[i].opcode, op) == 0)
        {
            valid_ops[i].f(stack, line_number);
            return;
        }
    }
    dprintf(STDOUT_FILENO, "Line %u: Unknown instrucion %s\n", line_number, op);
    exit(EXIT_FAILURE);
    
}

