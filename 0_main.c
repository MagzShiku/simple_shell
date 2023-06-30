#include "mjshell.h"

/**
 * main - entry point
 * Return: 0
 */

int main(void)
{
	for (;;)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			isInteractive();
		}
		else
		{
			isNOTinteractive();
		}

	}
	return (0);
}
