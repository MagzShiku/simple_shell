#include "mjshell.h"
/**
 * mjHelp - out help function
 * @args: the args to check out for
 * Return: 1
 */

int mjHelp(char **args)
{
	unsigned long int mj = 0;
	char *blt_in[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	mj = 0;
	(void)(**args);

	printf("\n --Hallo, how can I help you--\n");
	printf("type a command\n");
	printf("press Enter\n");
	printf("The built in commands\n");


	for (; mj < sizeof(blt_in) / sizeof(char *); mj++)
	{
		printf(" -> %s\n", blt_in[mj]);
	}

	printf("you can man also.\n");

	return (-1);

}
