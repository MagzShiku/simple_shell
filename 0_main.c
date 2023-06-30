#include "mjshell.h"

/**
 * main - entry point
 * Return: 0
 */

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		isInteractive();
	}
	else
	{
		isNOTinteractive();
	}

	return (0);
}
