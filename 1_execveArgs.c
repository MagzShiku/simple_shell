#include "mjshell.h"

/**
 * execveArgs - checks to see if the command is built in or not
 * @args: the arguments in the commands
 * Return: 1
 */

int execveArgs(char **args)
{
	unsigned long int i;
	char *blt_in[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	int (*blt_inFuncs[])(char **) = {
		&mjCommands, /*see file 4_mjCommands.c*/
		&mjEnvironment, /*5_mjEnvironments.c*/
		&mjHelp, /*see file 8_mjHelp.c*/
		&mjExit /*see file 6_mjExits.c*/


	};

	if (args[0] == NULL)
	{
		return (-1);
	}
	i = 0;
	for (; i < sizeof(blt_in) / sizeof(char *); i++)
	{
		if (strcmp(args[0], blt_in[i]) == 0)
		{
			return ((*blt_inFuncs[i])(args));
		}
	}
	return (execNew(args));	/*for execNew see 2_exeNew.c*/
}
