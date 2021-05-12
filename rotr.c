#include "monty.h"
#include <ctype.h>
/**
 * pop - print value on top of `stack', or exit if stack is empty
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;
    UNUSED(line_number);

    if (*stack)
    {
        *stack = tmp->prev;
    }
}