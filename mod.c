#include "monty.h"

/**
 * mod - the division of the second top element by the top element.
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sub = 0;

	if (var.stack_len < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	sub = tmp->next->n % tmp->n;
	tmp->next->n = sub;
	pop(stack, line_number);
}
