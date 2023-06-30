#include "mjshell.h"

/**
*execNew – A function that generates a new execution in a simple shell
*Authors Magdalene  and Jeniffer
*@mj_arg_s: string array
*Return: 1
*/
int execNew(char **mj_arg_s)
{
pid_t pid;
int mj_stat;

pid = fork();
if (pid ==  0)
{
if (execvp(mj_arg_s[0], mj_arg_s) == -1)
{
perror("error: process fail");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("forking error.");
}
else
{
do {
waitpid(pid, &mj_stat, WUNTRACED);
} while (!WIFEXITED(mj_stat) && !WIFSIGNALED(mj_stat));
}
return (-1);
}


