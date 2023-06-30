#include "shell.h"

/**
*shell_interactive - a function that interprets a UNIX command
*Authors: Magdalene and Jeniffer
*Return: void
*/
void shell_interactive(void)
{
char *mj_line;
char **mj_args;
int mj_status = -1;

do {
printf("mjShell$ ");
mj_line = read_line();
mj_args = split_line(mj_line);
mj_status = execute_args(mj_args);
free(mj_line);
free(mj_args);
if (mj_status >= 0)
{
exit(mj_status);
}
} while (mj_status == EOF);
}
