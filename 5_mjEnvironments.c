#include "mjshell.h"
/**
*mjEnviron - A function that prints our working environment
*Authors:Magdalene and Jeniffer
*@mj_arg_s: the argumtnts
*Return: 1
*/
int mjEnviron(char **mj_arg_s)
{
int i = 0;

(void)(**mj_arg_s);

while (environ[i])
{
write(STDOUT_FILENO, environ[i], strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
return (-1);
}


