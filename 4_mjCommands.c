
#include "mjshell.h"
/**
 * cdDir - A function that changes a directory
 * Authors:Magdalene a nd Jeniffer
 * @mj_arg_s: the directory to change into
 * Return: 1
 */
int cdDir(char **mj_arg_s)
{
if (mj_arg_s[1] == NULL)
{
fprintf(stderr, "did you mean… \"cd\"\n");
}
else
{
if (chdir(mj_arg_s[1]) != 0)
{
perror("error changing directories\n");
}
}
return (-1);
}

