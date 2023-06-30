#include "mjshell.h"

/**
 * isIinteractive - A function that will show the shell's interactive mode
 * Return: void
 */

void isIinteractive(void)
{
char **mj_arg_s;
char *input;
int mj_stat;
mj_stat = -1;

do {
printf("mjShell$ ");
input = readInput();
mj_arg_s = tknizer(input);
mj_stat = execveMj_arg_s(mj_arg_s);
free(input);
free(mj_arg_s);
if (mj_stat >= 0)
{
exit(mj_stat);
}
} while (mj_stat == -1);
}


