#include "mjshell.h"

/**
 * mjCommands - this will link to the command cd that changes dirs
 * @args: the dir in question
 * Return: 1 on success
 */

int mjCommands(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "did you mean \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0) /*can man chdir*/
		{
			fprintf(stderr, "Error changing directory");
		}
	}
	return (-1);
}
