#include "main.h"

/**
 * main - main program entry point
 * Return: 0 for success
 */

int main(void)
{
	char *mj_c_prompt;
	char *mj_input; /* a pointer to buffer input from stdin*/
	size_t size; /*stores allocated memory in bytes*/
	int cndtn; /* loop counter for the true value loop*/
	ssize_t _n_read; /*checks for number of characters read*/

	size = 0;
	mj_c_prompt = "mjshell$ ";

	cndtn = 1; /*creates an infinite loop while checking true (1)*/
	for (; cndtn; )
	{
		printf("%s", mj_c_prompt);
		_n_read = getline(&mj_input, &size, stdin);

		if (_n_read == -1)
		{
			printf(" \n");
			return (-1);
		}

		printf("%s\n", mj_input);
		free(mj_input);
		mj_input = NULL; /*return pointer to NULL after freeing memory */
	}
	return (0);
}
