#include "monty.h"
#include <ctype.h>
/**
 * rotl - The top element becomes the last one,the second top becomes the first
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	UNUSED(line_number);

	if (*stack)
	{
		*stack = tmp->next;
	}
}
