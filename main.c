#include "main.h"
#define MAX_ARRGS 100

int token_input(char *input, char **args);
void free_tokens(char **args, int token_num);
void input_handler(char *mj_input);
void mj_execve(char **args);
void pipe_commands(char **com1, char **com2);
int pipe_checker(char *input, char **commands);

/**
 * token_input - function to tokenize inout
 * @input: the variable name to hold the user input
 * @args: the parameter to hold the arguments
 * Return: the number of tokens token_num inserted
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

	while (1)
	{
		printf("%s", mj_c_prompt);
		_n_read = getline(&mj_input, &size, stdin);

		if (_n_read == -1)
		{
			printf("Disconnected...\n");
			break;
		}
		input_handler(mj_input);
	}
	free(mj_input);
	return (0);
}
/**
 * input_handler - function to handle user input
 * @mj_input: the input
 */
void input_handler(char *mj_input)
{
	char *the_pipe;
	char *mj_input_copy;
	char *com1;
	char *com2;
	int token_num;
	char *args[MAX_ARRGS];
	/*int res;*/

	mj_input[strcspn(mj_input, "\n")] = '\0';
	mj_input_copy = strdup(mj_input);
	if (mj_input_copy == NULL)
	{
		fprintf(stderr, "Error: failure to allocate memory\n");
		return;
	}
	if (strcmp(mj_input, "exit") == 0)
	{
		free(mj_input);
		exit(EXIT_SUCCESS);
	}
	/**
	 * we are adding here code that
	 * calls token_input
	 * pipe_commands
	 * free_token
	 * mj_execve
	 */
	token_num = token_input(mj_input, args);
	/*res = mjcmdHandling(args);*/

	the_pipe = strchr(mj_input, '|');
	if (the_pipe != NULL)
	{
		*the_pipe = '\0';
		com1 = mj_input;
		com2 = the_pipe + 1;
		pipe_commands(&com1, &com2);
	}
	else
	{
		if (token_num > 0)
		{
			mj_execve(args);
		}
		else
		{
			printf("No command entered...\n");
		}
		free_tokens(args, token_num);
	}
	free(mj_input_copy);
}
