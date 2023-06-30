#include "mjshell.h"
/**
 * mjEnvironment - access env variables
 * @args: the arguments getting us there
 * Return: 1
 */

int mjEnvironment(char **args)
{
	int i;

	(void)(**args);

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (-1);
}
