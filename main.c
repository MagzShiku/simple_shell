#include "main.h"
#define MAX_ARGS 10


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
 * @argc: Argument count
 * @argv: argument vector
 * Return: 0 for success
 */
int main(int argc, char *argv[])
{
	char *mj_c_prompt;
	char *mj_input; /* a pointer to buffer input from stdin*/
	size_t size; /*stores allocated memory in bytes*/
	ssize_t _n_read; /*checks for number of characters read*/
	const char *delim;
	int token_num;
	char *token;
	char *mj_input_copy;
	char *args[MAX_ARGS];
	int i;
	char **cmd_args;
	(void)argc;
	(void)argv;
		
	size = 0;
	mj_c_prompt = "mjshell$ ";
	mj_input = NULL;
	token_num = 0;
	delim = " ";
		
	while (1)
	{
		printf("%s", mj_c_prompt);
		free(mj_input);
		_n_read = getline(&mj_input, &size, stdin);

		if (_n_read == -1)
		{
			printf("Disconnected. \n");
			return (-1);
		}

		mj_input[strcspn(mj_input, "\n")] = '\0';
		mj_input_copy = mj_input_copy_fn(mj_input);

		if (mj_input_copy == NULL)
		{
			printf("Failed to allocate memory.\n");
			break;
		}
		
		if (strcmp(mj_input, "exit") == 0)
			break;

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

		if (token_num > 0)
		{
			cmd_args = malloc(sizeof(char *) * (token_num + 1));
			if (cmd_args == NULL)
			{
				perror("malloc failed");
				break;
			}

			for (i = 0; i < token_num; i++)
			{
				cmd_args[i] = args[i];

			}
			cmd_args[token_num] = NULL;
			mj_execve(cmd_args);			
			free(cmd_args);
		}
		free(mj_input_copy);
		mj_input_copy = NULL;
		token_num = 0;
	}

	free(mj_input);
	mj_input = NULL;

	return (0);
}
