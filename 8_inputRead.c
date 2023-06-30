#include "mjshell.h"

/**
*readInput –  A function that reads input from user
*Authors:Magdalene and Jeniffer
*Return: pointer to string input
*/
char *readInput(void)
{
size_t size_BuFFer = 0;        
char *input = NULL;
if (getline(&input, &size_BuFFer, stdin) == -1) 
{
if (feof(stdin))
{
free(input);
exit(EXIT_SUCCESS);
}
else
{
free(input);
perror("error: stdin read failure");
exit(EXIT_FAILURE);
}
}
return (input);
}

