#include "mjshell.h"

/**
*tknizer – A function that tokenizes the input
*Authors: Magdalene and Jeniffer
*@input: the string input
*Return: pointer to array
*/
char **tknizer(char *input)
{
int size_BuFFer = 64;	
int i = 0;
char **tkns = malloc(size_BuFFer * sizeof(char *));
char *tkn;

if (!tkns)
{
fprintf(stderr, "Token memory allocation failed\n");
exit(EXIT_FAILURE);
}
tkn = strtok(input, MJ_DELIM );
while (tkn != NULL)
{
if (tkn[0] == '#')
{
break;
}
tkns[i] = tkn;
i++;
if (i >= size_BuFFer)
{
size_BuFFer += size_BuFFer;
tkns = realloc(tkns, size_BuFFer * sizeof(char *));
if (!tkns)
{
fprintf(stderr, "Token memory allocation failed");
exit(EXIT_FAILURE);
}
}
tkn = strtok(NULL, MJ_DELIM );
}
tkns[i] = NULL;
return (tkns);
}
