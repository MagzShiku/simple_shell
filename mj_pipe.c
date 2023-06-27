#include "main.h"
int pipe_checker(char *input, char **commands);
int pipe_maker(int mjPipe[2]);
void mjExecutePipe(char **command, int mjPipe[2]);
void awaitingChildren(void);
void pipe_commands(char **com1, char **com2);
/**
 * pipe_checker - helps us be on the lookout for pipe
 * @input: the input
 * @commands: well, the commands
 * Return: 1 on lail, 0 on no pipe
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
 * pipe_maker - creates a pipe
 * @mjPipe: array to store file desc
 * Return: 0 on success, -1 on failure
 */
int pipe_maker(int mjPipe[2])
{
	int res = pipe(mjPipe);

	if (res < 0)
	{
		printf("\nFailed to initialize pipe...");
	}
	return (res);
}
/**
 * mjExecutePipe - executes the pipe functions
 * @command: command being executed
 * @mjPipe: pipe file desc
 */
void mjExecutePipe(char **command, int mjPipe[2])
{
	close(mjPipe[0]);
	dup2(mjPipe[1], STDOUT_FILENO);
	close(mjPipe[1]);
	mj_execve(command);
}
/**
 * awaitingChildren - waits for child process
 */
void awaitingChildren(void)
{
	pid_t pid;
	int child_status;

	pid = wait(&child_status);
	if (pid > 0)
	{
		while (1)
		{
			pid = waitpid(-1, &child_status, WNOHANG);
			if (pid <= 0)
			{
				break;
			}
		}
	}
}

/**
 * pipe_commands - this helps me to pipe commands
 * @com1: command 1
 * @com2: command 2
 */
void pipe_commands(char **com1, char **com2)
{
	int mj_pipe[2], res;
	pid_t first_born, second_born;

	res = pipe_maker(mj_pipe);
	while (res < 0)
	{
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
		mjExecutePipe(com1, mj_pipe);
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
		awaitingChildren();
	}
}

