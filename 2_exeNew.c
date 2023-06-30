#include "mjshell.h"

/**
 * execNew - this bring in a new process execution
 * @args: the arguments in the process
 * Return: 1 for success, 0 for failure
 */

int execNew(char **args)
{
	pid_t mjPid;
	int _status;

	mjPid = fork();

	if (mjPid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "Cannot complete new child process\n");
		}
		exit(EXIT_FAILURE);
	}
	else if (mjPid < 0)
	{
		fprintf(stderr, "Forking Error\n");
	}
	else
	{
		do {
			waitpid(mjPid, &_status, WUNTRACED);
		} while (!WIFEXITED(_status) && !WIFSIGNALED(_status));

	}
	return (-1);
}
