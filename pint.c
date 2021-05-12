#include "monty.h"
/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{

	stack_t *tmp = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}
