#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (var.stack_len != 1)
	{
		(*stack)->next->prev = (*stack)->prev;
		(*stack)->prev->next = (*stack)->next;
		*stack = (*stack)->next;
	}
	else
		*stack = NULL;

	free(tmp);
	var.stack_len--;
}
