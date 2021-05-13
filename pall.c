#include "monty.h"

/**
 * pall -  prints all the values on the stack, starting from the top.
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	UNUSED(line_number);
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
