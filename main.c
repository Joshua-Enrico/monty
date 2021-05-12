#include "monty.h"


/**
 * main - Monty bytecode interpreter
 * @argc: numbers of arguments passed
 * @argv: arrays of argument
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	/* declaring needed variables*/
	char *lineptr = NULL, *op = NULL;
	FILE *file = NULL;
	size_t n = 0;
	/* var to get lines numbers */
	unsigned int line_number = 0;
	/* declarin stack that  will be used*/
	stack_t *stack = NULL;

	var.queue = 0;
	var.stack_len = 0;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* Here we read the given file*/
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*here we need to end and close some processes on exit */
	on_exit(free_lineptr, &lineptr);
	on_exit(free_stack, &stack);
	on_exit(close_File, &lineptr);
	/* here we fork and passes arguments to match a op*/
	while (getline(&lineptr, &n, file) != -1)
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
