#include "shell.h"

/**
 * mj_new_process - create a new process
 * @mj_args: array of strings that contains the command and its flags
 *Authors:Magdalene and Jeniffer
 * Return: 1 if success, 0 otherwise.
 */
int mj_new_process(char **mj_args)
{
	pid_t pid;
	int mj_status;

	pid = fork();

	if (pid ==  0)
	{
		if (execvp(mj_args[0], mj_args) == -1)
		{
			perror("error in new_process: child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("error in new_process: forking");
	}
	else
	{
		do {
			waitpid(pid, &mj_status, WUNTRACED);
		} while (!WIFEXITED(mj_status) && !WIFSIGNALED(mj_status));
	}
	return (-1);
}
