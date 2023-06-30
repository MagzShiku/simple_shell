#include "mjshell.h"
/**
 * mjHelp - out help function
 * @args: the args to check out for
 * Return: 1
 */

int mjHelp(char **args)
{
	unsigned long int i = 0;
	char *blt_in[] = {
		"cd",
		"env",
		"help",
		"exit"
	};

	(void)(**args);

	printf("\n --Hallo, how can I help you--\n");
	printf("type a command\n");
	printf("press Enter\n");
	printf("The built in commands\n");

	i = 0;
	while (i < sizeof(blt_in) / sizeof(char *))
	{
		printf(" -> %s\n", blt_in[i]);
		i++;
	}

	printf("you can man also.\n");

	return (-1);

}
