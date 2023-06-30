#include "shell.h"

/**
 * mj_exit - A function that terminates normal process in a shell
 * @mj_args: empty args parsed in a command line
 *Authors:Magdalene and Jeniffer
 * Return: 0 to terminate the process
 */
int mj_exit(char **mj_args)
{
	if (mj_args[1])
	{
		return (atoi(mj_args[1]));
	}
	else
	{
		return (0);
	}
}
