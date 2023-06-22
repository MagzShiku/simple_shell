#include "main.h"

/**
 * mj_execve - A function to execute a command
 *
 * @argv: an argument
 */

void mj_execve(char *argv[])
{
	char *mj_cmd;

	mj_cmd = NULL;

	if (argv)
	{
		mj_cmd = argv[0];

		if (execve(mj_cmd, argv, NULL) == -1)
		{
			perror("mjshell Error:");
		}
	}
}
