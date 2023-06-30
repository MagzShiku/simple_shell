#include "mjshell.h"
/**
 * strmRead - reads lines from stream
 * Return: pointer to pointer to lines read
 */
char *strmRead(void)
{
	int i = 0;
	int bufSize = 1024;
	char *input;
	int c;

	input = malloc(sizeof(char) * bufSize);
	if (!input)
	{
		fprintf(stderr, "Read-stream failure\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar(); /*standard input/output library in C*/
		if (c == EOF)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else if (c == '\n')
		{
			input[i] = '\0';
			return (input);
		}
		else
		{
			input[i] = c;
		}
		i++;
		if (i >= bufSize)
		{
			bufSize *= 2;
			input = realloc(input, bufSize);
			if (!input)
			{
				fprintf(stderr, "Reallocation in reading stream has failed\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
