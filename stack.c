#include "monty.h"
/**
 * stack_m - sets the format of the data to a stack (LIFO).
 * @stack: double pointer to head of stack
 * Description: This is the default behavior of the program.
 * @line_number: line number of current operation
 *
 * Return: void
 */
void stack_m(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	var.queue = STACK;
}
