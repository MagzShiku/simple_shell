#include "shell.h"

/**
 *mj_read_line - A function that reads a line from stdin
 *Authos:Magdalene and Jeniffer
 *Return: pointer that points to a string with the input
 */
char *mj_read_line(void)
{
	char *mj_line = NULL;

	size_t mj_input;

	mj_input = 0;

	if (getline(&mj_line, &mj_input, stdin) == EOF)
	{
		if (feof(stdin))
		{
			free(mj_line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(mj_line);
			fprintf(stderr,"failed to read command");
			exit(EXIT_FAILURE);
		}
	}
	return (mj_line);
}
