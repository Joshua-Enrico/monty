#include "monty.h"
#include <ctype.h>

/**
 * pop - removes the top element of the stack.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int Linenumber)
{
	stack_t *pop = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't pop an empty stack\n",
			Linenumber);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	if (var.stack_len != 1)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(pop);
	var.stack_len--;
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int Linenumber)
{
	stack_t *tmp = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", Linenumber);
		exit(EXIT_FAILURE);
	}
	if (!isascii(tmp->n))
	{
		dprintf(STDERR_FILENO,
				"L%u: can't pchar, value out of range\n",
				Linenumber);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", tmp->n);
}

/**
 * sub - subtracts the top element from the second top element of the stack.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int Linenumber)
{
	stack_t *tmp = *stack;
	int sub = 0;

	if (var.stack_len < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", Linenumber);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	sub = tmp->next->n - tmp->n;
	tmp->next->n = sub;
	pop(stack, Linenumber);
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int Linenumber)
{

	stack_t *tmp = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", Linenumber);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}

/**
 * mod - the division of the second top element by the top element.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int Linenumber)
{
	stack_t *tmp = *stack;
	int sub = 0;

	if (var.stack_len < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", Linenumber);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", Linenumber);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	sub = tmp->next->n % tmp->n;
	tmp->next->n = sub;
	pop(stack, Linenumber);
}
