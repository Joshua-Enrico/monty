#include "monty.h"
#include <ctype.h>
/**
 * pop - print value on top of `stack', or exit if stack is empty
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;

        if (var.stack_len == 0)
    {
        dprintf(STDOUT_FILENO, "L%u: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    if(!isascii(tmp->n))
    {
        dprintf(STDOUT_FILENO, "L%u: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", tmp->n);
}