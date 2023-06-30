#include "shell.h"

/**
 * mj_read_stream - A function that reads a line from the stream in a simple shell
 *Authors:Magdalene and Jeniffer
 * Return: pointer that points the the read line
 */
char *mj_read_stream(void)
{
	int mj_input = 256;
	int mj;
	char *mj_line;
	int mj_char;

	mj_line = malloc(sizeof(char) * mj_input);
	mj = 0;

	if (mj_line == NULL)
	{
		fprintf(stderr, "\nfailure to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		mj_char = getchar(); 
		if (mj_char == -1)
		{
			free(mj_line);
			exit(EXIT_SUCCESS);
		}
		else if (mj_char == '\n')
		{
			mj_line[mj] = '\0';
			return (mj_line);
		}
		else
		{
			mj_line[mj] = mj_char;
		}
		mj++;
		if (mj >= mj_input)
		{
			mj_input += mj_input;
			mj_line = realloc(mj_line, mj_input);
			if (mj_line == NULL)
			{
				fprintf(stderr, "\n\n failure on reallocation\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
