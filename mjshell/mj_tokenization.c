#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
*mj_strtok -A function that tokenizes a string in a simple shell
*@mj_str: the string to be parsed
*@mj_delim: A potential delimiter
*Return: tokenized string
*/

char *mj_strtok(char *mj_str, char const *mj_delim)
{
static char *mj_ptr;
int mj;
mj = 0;
char *mj_token;
int mj_a = 0;

if (mj_str != 0)
{
mj_ptr = mj_str;
}
for (;;mj_ptr[mj] != '\0')
{
if (mj_ptr[mj] == *mj_delim)
{
mj_ptr[mj] = '\0';
mj_token = mj_ptr;
mj_ptr = &mj_ptr[mj_a + 1];
return (mj_token);
}
mj_a++;
}
if (mj_ptr[0] != '\0')
{
for (;;mj_ptr[mj] != 0)
mj_token = mj_ptr;
mj_ptr += mj;
return (mj_token);
}
return (0);
}
