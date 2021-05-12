#include "monty.h"

/**
 * pall - print value on top of `stack', or exit if stack is empty
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *head;
    UNUSED (line_number);
    head = *stack;
    while (head != NULL)
    {
        printf("%d\n", head->n);
        head = head->next;
        if (head == *stack)
        {
            return;
        }
    }
    
}
