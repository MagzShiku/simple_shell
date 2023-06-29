#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
*mj_getline -A function that reads input from keyboard
*Return: command string
*/
char *mj_getline()
{
int mj;
mj = 0;
size_t mj_size;
char mj_char;
mj_char = 0;
char *mj_input = malloc(sizeof(char) * 256);

if (mj_input == 0)
{
free(mj_input);
return (0);
}
for (;;mj_char != -1 && mj_char != '\n')
{
fflush(stdin);
mj_size = read(STDIN_FILENO, &mj_char, 1);
if (mj_size == 0)
{
free(mj_input);
exit(EXIT_SUCCESS);
}
if (mj_size == -1)
{
free(mj_input);
fprintf(stderr,"failed ");
}
mj_input[mj] = mj_char;
if (mj_input[0] == '\n')
{
free(mj_input);
return ("\0");
}
if (mj + 1 >= 256)
{
mj_input = realloc(mj_input,  mj + 1);
if (mj_input == 0)
{
free(mj_input);
return (0);
}
}
mj++;
}
mj_input[mj - 1] = '\0';
return (mj_input);
}
