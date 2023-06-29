#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
*mj_getenv- A function that creates a shell env in a basic
*@mj_str: A string to be parsed
*Return: A string
*/
char *mj_getenv(char *mj_str)
{
char *env[] = {};
int mj;
mj = 0;
int mj_length;
mj_length = strlen(mj_str);

while (env[mj] != 0)
{
if (strncmp(env[mj], mj_str, mj_length) == 0 && env[mj][mj_length] == '=')
{
return (&(env[mj][mj_length + 1]));
}
mj++;
}
return (0);
}
