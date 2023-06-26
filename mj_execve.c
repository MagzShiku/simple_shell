#include "main.h"
#include <unistd.h>

/**
 * mj_execve - A function to execute a command
 *
 * @args: an argument
 */

void mj_execve(char **args)
{
	pid_t mj_pid;
	int status;
			
	mj_pid = fork();

	if (mj_pid == 0)
	{
		execvp(args[0], args);
		fprintf(stderr, "%s: 1: %s: not found\n", args[0], args[0]);
		exit(EXIT_FAILURE);
	}
	else if (mj_pid < 0)
	{
		fprintf(stderr, "Error: forking failed...\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(mj_pid, &status, WUNTRACED);

		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
