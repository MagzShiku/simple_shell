
#include "mjshell.h"

/**
*execveMj_arg_s –A fuction that checks if the comds are part of builtin
*Authors: Magdalene and Jeniffer
*@mj_arg_s: commands
*Return: 1, otherwise 0
*/
int execveMj_arg_s(char **mj_arg_s)
{
char *terminal_functions[] = {
"cd",
"env",
"help",
"exit"
};
int (*executableFunction[])(char **) = {
&cdDir,
&mjEnviron,
&needHelp,
&mjExit
};

long unsigned int i = 0;
if (mj_arg_s[0] == NULL)
{
return (-1);
}
for (; i < sizeof(terminal_functions) / sizeof(char *); i++)
{
if (strcmp(mj_arg_s[0], terminal_functions[i]) == 0)
{
return ((*executableFunction[i])(mj_arg_s));
}
}
return (execNew(mj_arg_s));
}

