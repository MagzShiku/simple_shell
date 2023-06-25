#include "main.h"
#define MAX_ARRGS 10

/**
 * token_input - function to tokenize inout
 * @input: the variable name to hold the user input
 * @args: the parameter to hold the arguments
 * Return: the number of tokens token_num
 */
int token_input(char *input, char **args)
{
	int token_num = 0;
	const char *delim = " ";
	char *token = strtok(input, delim);

	while (token != NULL && token_num < MAX_ARRGS - 1)
	{
		args[token_num] = strdup(token);
		token_num++;
		token = strtok(NULL, delim);
	}

	args[token_num] = NULL;
	return (token_num);
}
/**
 * free_tokens - function to free tokens
 * @args: the arguments in the function
 * @token_num: the number of tokens
 */
void free_tokens(char **args, int token_num)
{
	int mj;

	for (mj = 0; mj < token_num; mj++)
	{
		free(args[mj]);
		args[mj] = NULL;
	}
}
/**
 * main - main entry to function
 * Return: 0 on success
 */
int main(void)
{
	char *mj_c_prompt = "mjshell$ ";
	char *mj_input = NULL;
	size_t size = 0;
	ssize_t _n_read;
	int token_num;
	char *args[MAX_ARRGS];
	char *mj_input_copy;

	while (1)
	{
		printf("%s", mj_c_prompt);
		_n_read = getline(&mj_input, &size, stdin);

		if (_n_read == -1)
		{
			printf("Disconnected...\n");
			break;
		}
		mj_input[strcspn(mj_input, "\n")] = '\0';
		mj_input_copy = strdup(mj_input);
		if (mj_input_copy == NULL)
		{
			fprintf(stderr, "Error: failure to allocate memory\n");
			break;
		}
		if (strcmp(mj_input, "exit") == 0)
		{
			free(mj_input_copy);
			break;
		}
		token_num = token_input(mj_input_copy, args);
		if (token_num > 0)
			mj_execve(args);
		else
			printf("No command entered...\n");
		free_tokens(args, token_num);
		free(mj_input_copy);
	}
	free(mj_input);
	return (0);
}
