#include "mjshell.h"

/**
*mjExit – A function that exists from our shell
*Authors:Magdalene and Jeniffer
*@mj_arg_s: the arguments
*Return: 0
*/
int mjExit(char **mj_arg_s)
{
if (mj_arg_s[1])
{
return (atoi(mj_arg_s[1]));
}
else
{
return (0);
}
}

