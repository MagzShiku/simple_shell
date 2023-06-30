#include "shell.h"

/**
 * mj_help - A function that prints help
 * @mj_args: command linearguments
 * Authors: Magdalene and Jeniffer
 * Return: 1 on success, otherwise 0
 */
int mj_help(char **mj_args)
{
	char *mj_builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	long unsigned int mj;

	mj = 0;

	(void)(**mj_args);

	fprintf(stdout,"\n\n*****mjshell help******\n");
	fprintf(stdout, "\n\nEnter a command and its arguments, press enter\n");
	printf("\n\nBuilt-in commands:\n");
	for (; mj < sizeof(mj_builtin_func_list) / sizeof(char *); mj++)
	{
		fprintf(stdout, "  -> %s\n", mj_builtin_func_list[mj]);
	}
	fprintf(stdout, "\n\n Make the man Page your dear friend\n\n");
	return (-1);
}
