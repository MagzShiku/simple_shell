#include "mjshell.h"
/**
*is_NotInteractive – A function that takes us back to terminal prompt
*Authors:Magdalene and Jeniffer
*Return: void
*/
void is_NotInteractive(void)
{
char **mj_arg_s;
char *input;
int mj_stat = -1;

do {
input = _Stream();
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


