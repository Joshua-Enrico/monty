#include "monty.h"


/**
 * main - Monty bytecode interpreter
 * @argc: numbers of arguments passed
 * @argv: arrays of argument
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	FILE *fs = NULL;
	char *lineptr = NULL, *op = NULL;
	size_t n = 0;

	var.queue = 0;
	var.stack_len = 0;
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fs = fopen(argv[1], "r");
	if (fs == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	on_exit(free_lineptr, &lineptr);
	on_exit(free_stack, &stack);
	on_exit(close_File, fs);
	while (getline(&lineptr, &n, fs) != -1)
	{
		line_number++;
		op = strtok(lineptr, "\n\t\r ");
		if (op != NULL && op[0] != '#')
		{
			check_if_op_match(op, &stack, line_number);
		}
	}
	exit(EXIT_SUCCESS);
}
