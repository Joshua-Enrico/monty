#include "monty.h"
#include <ctype.h>

/**
 * pall -  prints all the values on the stack, starting from the top.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int Linenumber)
{
	stack_t *head;

	UNUSED(Linenumber);
	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
		{
			return;
		}
	}

}

/**
 * check_for_digit - print value on top of `stack', or exit if stack is empty
 * @arg: double pointer to head of stack
 *
 * Return: void
 */
static int check_for_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 * push - print value on top of `stack', or exit if stack is empty
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int Linenumber)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t ");

	if (arg == NULL || check_for_digit(arg))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", Linenumber);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_node(stack, n))
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}

/**
 * nop -  does not do anything.
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int Linenumber)
{
	UNUSED(stack);
	UNUSED(Linenumber);
}

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to head of stack
 * @Linenumber: line number of current operation
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int Linenumber)
{
	int n = 0;

	if (var.stack_len < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", Linenumber);
		exit(EXIT_FAILURE);
	}
	n += (*stack)->n;
	pop(stack, Linenumber);
	(*stack)->n += n;
}
