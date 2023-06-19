#include "main.h"

/**
 * main - main - program entry point
 * Return: 0 for success
 */

int main(void)
{
	char *mj_c_prompt;
	char *mj_input; /* a pointer to buffer input from stdin*/
	size_t size; /*stores allocated memory in bytes*/
	int cndtn;

	size = 0;
	mj_c_promts = "mjshell";

	cndtn = 1; /*creates an infinite loop while checking true (1)*/
	for (; cndtn; cndtn)
	{
		printf("%s", mj_c_prompt);
		getline(&mj_input, &size, stdin);

		printf("%s\n", mj_input);
		free(mj_input);
	}
	return (0);
}
