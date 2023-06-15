#include "main.h"

/**
 * main - program entry point
 * @argc: Counts the number of aurguments
 * @arg: Counts the number of vectors
 * Return: 0 for success
 */

int main()
{
	char *mj_c_prompt;
	char *mj_input; /* a pointer to buffer input from stdin*/
	size_t size;/*stores allocated memory in bytes*/

	size = 0;
	mj_c_prompt = "mjshell$";

	printf("%s", mj_c_prompt);
	getline(&mj_input, &size, stdin);

	printf("%s\n", mj_input);
	free(mjinput);
	return (0);
}
