#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element.
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int sub = 0;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	sub = tmp->next->n * tmp->n;
	tmp->next->n = sub;
	pop(stack, line_number);

	var.stack_len--;
}
