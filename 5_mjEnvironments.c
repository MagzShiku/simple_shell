#include "mjshell.h"
/**
 * mjEnvironment - access env variables
 * @args: the arguments getting us there
 * Return: 1
 */

int mjEnvironment(char **args)
{
	int mj;

	mj = 0;

	(void)(**args);

	while (environ[mj])
	{
		write(STDOUT_FILENO, environ[mj], strlen(environ[mj]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (-1);
}
