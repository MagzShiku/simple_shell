#include "mjshell.h"
/**
 * mjExit - exits the terminsl
 * @args: the args to check out for
 * Return: 0 for success
 */

int mjExit(char **args)
{
	while (args[1])
	{
		return (atoi(args[1]));
	}
	else
	{
		return (0);
	}
}
