#include "main.h"
/**
 * mjcmdHandlling -A function that is meant to handle built in commands
 * @str_mj: The parsed string of characters
 * Return:0
 */
int mjcmdHandling(char *str_mj)
{
int Cmds_num = 1024, mj, switchmjArgs;
char *mjCmd[Cmds_num], *USER;
mjCmd[0] = "exit";
mjCmd[1] = "cd";
mjCmd[2] = "hello";
mjCmd[3] = "setenv";
mjCmd[4] = "unsetenv";
mj = 0;
switchmjArgs = 0;
while (mj < Cmds_num)
{
if (strcmp(*str_mj[0], mjCmd[mj]) == 0)
{
switchmjArgs = mj + 1;
break;
}
mj++;
}
switch (switchmjArgs)
{
case 1:
fprintf(stdout, "\n\nIt's a wrap from mj_shell\n");
exit(0);
case 2:
if (str_mj[1] != NULL)
{
chdir(str_mj[1]);
return (1);
}
else
{
fprintf(stderr, "Please specify a directory to change to\n");
return (0);
}
case 3:
USER = getenv("USER");
fprintf(stdout, "\n\n How are you doing today %s.\n"
USER);
return (1);
}
