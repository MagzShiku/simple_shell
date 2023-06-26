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
	/*int mj_pipe[2];*/

	/*if (pipe(mj_pipe) == -1)
	{
		fprintf(stderr, "Error: Failed to pipe\n");
		exit(EXIT_FAILURE);
	}*/
		
	mj_pid = fork();

	if (mj_pid == 0)
	{
		/*close(mj_pipe[1]);

		dup2(mj_pipe[0], STDIN_FILENO);

		close(mj_pipe[0]);*/

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
		/*close(mj_pipe[0]);

		dprintf(mj_pipe[1], "%s\n", args[0]);

		close(mj_pipe[1]);*/

		do {
			waitpid(mj_pid, &status, WUNTRACED);

		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
