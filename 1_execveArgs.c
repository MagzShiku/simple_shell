#include "mjshell.h"

/**
 * execveArgs - checks to see if the command is built in or not
 * @args: the arguments in the commands
 */

int execveArgs(char **args)
{
	long unsigned int i;
	char *blt_inFuncs[] = {
		"cd";
		"env";
		"help";
		"exit";
	};
	int (*blt_inFuncs[])(char **) = {
		&mjCommands; /*see file 4_mjCommands.c*/
		&mjEnvironments; /*5_mjEnvironments.c*/
		&mjHelp; /*see file 8_mjHelp.c*/
		&mjExit; /*see file 6_mjExits.c*/


	};

	if (!args[0])
	{
		return(-1);
	}
	
	i = 0;
	while (i < sizeof(blt_inFuncs) / sizeof(char *))
	{
		if (strcmp(args[0], blt_inFuncs[i]) == 0)
		{
			return ((blt_inFuncs[i])(args));
		}
		i++;
	}
	return (execNew(args));	/*for execNew see 2_exeNew.c*/
}
