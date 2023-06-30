#include "mjshell.h"

/**
 * main - main entry into function
 * Authors: Magdalene and Jeniffer
 * Return: 0 on success
 */
int main(void)
{
if (isatty(STDIN_FILENO) == 1)
{
isIinteractive();
}
else
{
is_NotInteractive();
}
return (0);
}

