#include "shell.h"

/**
 * mj_cd - A function that changes the working dir of the
 * current shell execution environment
 * @mj_args: the command line target directory
 *Author: Magdalene and Jeniffer
 * Return: 1 one success, otherwise 0.
 */
int mj_cd(char **mj_args)
{
	if (mj_args[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(mj_args[1]) != 0)
		{
			fprintf(stderr, "error in own_cd.c: changing dir\n");
		}
	}
	return (-1);
}
