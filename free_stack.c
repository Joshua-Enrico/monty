#include "monty.h"

/**
 * free_stack - free stack on exit
 * @status: exit status
 * @arg: pointer to line
 *
 * Return: void
 */
void free_stack(int status, void *arg)
{
	stack_t **stack;
	stack_t **next;

	UNUSED(status);

	stack = (stack_t **)arg;

	if (*stack)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}

	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	var.stack_len = 0;
}
