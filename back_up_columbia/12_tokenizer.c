#include "shell.h"

/**
 *mj_split_line - A function that splits a string into multiple
 *strings in a simple shell
 *@mj_line: The string to be splited
 *Authors:Magdalene and Jeniffer
 *Return: pointer that points to the new array
 */
char **nj_split_line(char *mj_line)
{
	int mj_input;
	int mj;
	char **mj_tokens;
	char *mj_token;

	mj_input = 256;
	mj_tokens = malloc(mj_input * sizeof(char *));
	mj = 0;

	if (!mj_tokens)
	{
		fprintf(stderr, "\n\nfailure to allocate in split_line: tokens\n");
		exit(EXIT_FAILURE);
	}
	mj_token = strtok(mj_line, MJ_TOK_DELIM);
	while (mj_token != NULL)
	{
		if (mj_token[0] == '#')
		{
			break;
		}
		mj_tokens[mj] = mj_token;
		mj++;
		if (mj >= mj_input)
		{
			mj_input += mj_input;
			mj_tokens = realloc(mj_tokens, mj_input * sizeof(char *));
			if (!mj_tokens)
			{
				fprintf(stderr, "\n\nerror to reallocate in split_line: tokens");
				exit(EXIT_FAILURE);
			}
		}
		mj_token = strtok(NULL, MJ_TOK_DELIM);
	}
	mj_tokens[mj] = NULL;
	return (mj_tokens);
}
