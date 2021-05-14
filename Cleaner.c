#include "monty.h"

/**
 * free_File_line - free line pointer returned by getline
 * @status: exit status
 * @argument: pointer to line
 *
 * Return: void
 */
void free_File_line(int status, void *argument)
{
	char **lineptr = argument;

	UNUSED(status);
	if (*lineptr != NULL)
		free(*lineptr);
}

/**
 * free_stack_list - free stack on exit
 * @status: exit status
 * @argument: pointer to line
 *
 * Return: void
 */
void free_stack_list(int status, void *argument)
{
	stack_t **stack;
	stack_t *next;

	UNUSED(status);

	stack = (stack_t **)argument;

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

/**
 * close_File - clse "file" on exit
 * @status: exit status
 * @argument: pointer to line
 *
 * Return: void
 */
void close_File(int status, void *argument)
{
	FILE *fs;

	UNUSED(status);

	fs = (FILE *) argument;
	fclose(fs);
}
