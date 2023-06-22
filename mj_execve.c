#include "main.h"

/**
 * mj_execve - A function to execute a command
 *
 * @argv: an argument
 */
extern char **environ;
void mj_execve(char *argv[])
{
	char *mj_cmd;
	char *the_cmd;

	mj_cmd = NULL;
	the_cmd = NULL;

	if (argv != NULL && argv[0] != NULL)
	{
		mj_cmd = argv[0];
		the_cmd = mj_path(mj_cmd);

		if (the_cmd != NULL)
		{
			if (execve(the_cmd, argv, environ) == -1)
			{
				perror("mjshell Error");
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			fprintf(stderr, "mjshell: Command not found: %s\n", mj_cmd);
			exit(EXIT_FAILURE);
		}
	}
}
