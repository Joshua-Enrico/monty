#include "monty.h"
#include <ctype.h>
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDOUT_FILENO, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!isascii(tmp->n))
	{
		dprintf(STDOUT_FILENO,
				"L%u: can't pchar, value out of range\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", tmp->n);
}
