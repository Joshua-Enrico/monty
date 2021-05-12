#include "monty.h"
#include <ctype.h>
/**
 * pop - print value on top of `stack', or exit if stack is empty
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;
    unsigned int counter = 0;

    while (counter < line_number)
    {
        if(tmp->n == 0 || (!isalnum(tmp->n)))
        {
            break;
        }
    printf("%c", tmp->n);
    tmp = tmp->next;
    counter++;
    }
    printf("\n");
    
}