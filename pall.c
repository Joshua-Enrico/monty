#include "monty.h"


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
