#include "main.h"
/**
 * pipe_checker - helps us be on the lookout for pipe
 * @input: the input
 * @commands: well, the commands
 * Return: 1 on lail, 0 on no pipe what to do
 */
int pipe_checker(char *input, char **commands)
{
	int i = 0, yes_pipe = 0;

	while (i < 2)
	{
		commands[i] = strsep(&input, "|");
		if (commands[i] == NULL)
			break;
		i++;
	}
	if (commands[1] != NULL)
		yes_pipe = 1;
	return (yes_pipe);
}
/**
 * pipe_commands - this helps me to pipe commands
 * @com1: command 1
 * @com2: command 2
 */
void pipe_commands(char **com1, char **com2)
{
	int mj_pipe[2], res, child_status;
	pid_t first_born, second_born, pid;

	res = pipe(mj_pipe);
	while (res < 0)
	{
		printf("\n failed to initialize pipe...");
		return;
	}
	first_born = fork();
	if (first_born < 0)
	{
		printf("\nforking failed");
		return;
	}
	if (first_born == 0)
	{
		close(mj_pipe[0]);
		dup2(mj_pipe[1], STDOUT_FILENO);
		close(mj_pipe[1]);
		mj_execve(com1);
	} else
	{
		second_born = fork();
		if (second_born < 0)
		{
			printf("\nforking failed");
			return;
		}
		if (second_born == 0)
		{
			close(mj_pipe[1]);
			dup2(mj_pipe[0], STDIN_FILENO);
			close(mj_pipe[0]);
			mj_execve(com2);
		} else
		{
			close(mj_pipe[0]);
			close(mj_pipe[1]);
		}
		while ((pid = wait(&child_status)) > 0)
		{
		}
	}
}
