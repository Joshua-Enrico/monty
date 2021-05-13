#include "monty.h"
#include <ctype.h>

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
 * @line_number: line number of current operation
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t ");

	if (arg == NULL || check_for_digit(arg))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_node(stack, n))
	{
		dprintf(STDERR_FILENO, "Error: mallsoc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}
