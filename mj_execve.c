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
		fprintf(stderr, "Error: command failed...\n");
		fprintf(stderr, "Exiting...\n");
		exit(EXIT_FAILURE);
	}
	else if (mj_pid < 0)
	{
		fprintf(stderr, "Error: forking failed...\n");
		fprintf(stderr, "Exiting...\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(mj_pid, &status, WUNTRACED);

		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
