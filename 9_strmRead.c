#include "mjshell.h"
/**
*_Stream - function that reads a streaminput
*Author:Magdalene and Jeniffer
*Return: pointer to readinput
*/
char *_Stream(void)
{
int c;
int size_BuFFer = 1024;
int i = 0;
char *input = malloc(sizeof(char) * size_BuFFer);

if (input == NULL)
{
fprintf(stderr, "memory reallocation failed");
exit(EXIT_FAILURE);
}
while (1)
{
c = getchar();
if (c == EOF)
{
free(input);
exit(EXIT_SUCCESS);
}
else if (c == '\n')
{
input[i] = '\0';
return (input);
}
else
{
input[i] = c;
}
i++;

if (i >= size_BuFFer)
{
size_BuFFer += size_BuFFer;
input = realloc(input, size_BuFFer);
if (input == NULL)
{
fprintf(stderr, "memory reallocation failed");
exit(EXIT_FAILURE);
}
}
}
}
