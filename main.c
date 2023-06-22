#include "main.h"
#define MAX_ARGS 10
void mj_execve(char *argv[]);
/**
 * mj_input_copy_fn - function to copy mj_input
 * @mj_input: the variable holding strings to copy
 * Return: mj_input_copy, NULL on failure.
 */

char *mj_input_copy_fn(const char *mj_input)
{
	size_t len;
	char *mj_input_copy;

	len = strlen(mj_input);
	mj_input_copy = malloc(sizeof(char) * (len + 1));

	if (mj_input_copy == NULL)
	{
		fprintf(stderr, "Error: failure to allocate memory.\n");
		return (NULL);
	}

	strcpy(mj_input_copy, mj_input);
	return (mj_input_copy);
}

/**
 * main - main program entry point
 * Return: 0 for success
 */

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
	char *mj_c_prompt;
	char *mj_input; /* a pointer to buffer input from stdin*/
	size_t size; /*stores allocated memory in bytes*/
	int cndtn; /* loop counter for the true value for loop*/
	ssize_t _n_read; /*checks for number of characters read*/
	const char *delim;
	int token_num;
	char *token;
	char *mj_input_copy;
	char *args[MAX_ARGS];
	int i;
	char **cmd_args;
	char *cmd;

	size = 0;
	mj_c_prompt = "mjshell$ ";
	mj_input = NULL;
	token_num = 0;
	delim = "\n";

	cndtn = 1; /*creates an infinite loop while checking true (1)*/
	for (; cndtn; )
	{
		printf("%s", mj_c_prompt);
		_n_read = getline(&mj_input, &size, stdin);

		if (_n_read == -1)
		{
			printf("Disconnected. \n");
			break;
		}

		mj_input[strcspn(mj_input, "\n")] = '\0';
		mj_input_copy = mj_input_copy_fn(mj_input);

		if (mj_input_copy == NULL)
		{
			printf("Failed to allocate memory.\n");
			break;
		}

		token = strtok(mj_input, delim);
		for (; token != NULL; token = strtok(NULL, delim))
		{
			if (token_num >= MAX_ARGS - 1)
			{
				printf("Too many arguments.\n");
				break;
			}
			args[token_num] = strdup(token);
			token_num++;

		}
		args[token_num] = NULL;

		for (i = 0; i < token_num; i++)
		{
			cmd = args[i];
			cmd_args = malloc(sizeof(char *) * 2);
			cmd_args[0] = cmd;
			cmd_args[1] = NULL;

			mj_execve(cmd_args);

			free(cmd_args);
			free(args[i]);

		}

		free(mj_input_copy);
		mj_input_copy = NULL;
		token_num = 0;
	}

	free(mj_input);
	mj_input = NULL;

	return (0);
}
