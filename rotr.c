#include "monty.h"
#include <ctype.h>
/**
 * rotr - The last element of the stack becomes the top element of the stack
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
