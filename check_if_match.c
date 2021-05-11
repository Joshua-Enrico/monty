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
    opcodes_list_t valid_ops[] = {
        {"push", push},
        {"pall", pall},
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

void pall(stack_t **stack, unsigned int line_number)
{
    UNUSED(stack);
    UNUSED(line_number);
    dprintf(STDOUT_FILENO, "Still working on funciont\n");
    return;
}