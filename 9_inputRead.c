#include "mjshell.h"

/**
 * inputRead - receives the input command
 * Return: pointer to str
 */

char *inputRead(void)
{
	char *input;
	size_t bufSize;

	input = NULL;
	bufSize = 0;

	if (getline(&input, &bufSize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(input);
			fprintf(stderr, "Error reading from input");
			exit(EXIT_FAILURE);
		}
	}
	return (input);

}
