#include "mjshell.h"

/**
 * tokenizer - tokenizes the line so it can execute
 * @input: the input to be read
 * "input" related with other functions please look at other files
 * Return: pointer to array
 */

char **tokenizer(char *input)
{
	char *tkn;
	char **tokens;
	int i;
	int bufSize;

	bufSize = 64;
	tokens = malloc(bufSize * sizeof(char *));
	i = 0;

	if (tokens == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	tkn = strtok(input, MJ_DELIMITER);

	while (tkn != NULL)
	{
		if (tkn[0] == '#')
		{
		break;
		}
		tokens[i] = tkn;
		i++;

		if (i >= bufSize)
		{
			bufSize *= 2;
			tokens = realloc(tokens, bufSize * sizeof(char *));

			if (tokens == NULL)
			{
				fprintf(stderr, "mem realloc error\n");
				exit(EXIT_FAILURE);
			}
		}
		tkn = strtok(NULL, MJ_DELIMITER);
	}
	tokens[i] = NULL;
	return (tokens);
}
