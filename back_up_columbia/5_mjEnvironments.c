#include "shell.h"

/**
 * mj_env - A function that prints shell enviroment variables
 * @mj_args:The  arguments parsed to the command line
 *Authors: Magdalene and Jeniffer
 * Return: 1 on success, otherwise 0
 */
int mj_env(char **mj_args)
{
	int mj;

	mj = 0;

	(void)(**mj_args);


	while (environ[mj])
	{
		write(STDOUT_FILENO, environ[mj], strlen(environ[mj]));
		write(STDOUT_FILENO, "\n", 1);
	}
	mj++;
	return (-1);
}
