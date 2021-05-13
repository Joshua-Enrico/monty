#include "monty.h"

/**
 * close_File - clse "file" on exit
 * @status: exit status
 * @arg: pointer to line
 *
 * Return: void
 */
void close_File(int status, void *arg)
{
	FILE *fs;

	UNUSED(status);

	fs = (FILE *) arg;
	fclose(fs);
}
