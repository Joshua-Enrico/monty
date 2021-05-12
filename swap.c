#include "monty.h"

/**
 * pop - print value on top of `stack', or exit if stack is empty
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
		if (var.stack_len == 2)
	{
		*stack = (*stack)->next;
		return;
	}
	else
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		tmp->next->next->prev = tmp;
		tmp->prev = tmp->next;
		tmp->next = tmp->next->next;
		tmp->prev->next = tmp; 

		*stack = tmp->prev;
	}

}