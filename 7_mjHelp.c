#include "mjshell.h"
/**
*needHelp - A function that helps the user upon request
*Authors:Magdalene and Jeniffer
*@mj_arg_s: the arguments inputed
*Return: 1
*/
int needHelp(char **mj_arg_s)
{
char *terminal_functions[] = {
"cd",
"env",
"help",
"exit"
};
unsigned long int i = 0;
(void)(**mj_arg_s);

printf("\n:::type ---help for support\n");
printf("enter command…press enter\n");
printf(":\n");

for (; i < sizeof(terminal_functions) / sizeof(char *); i++)
{
printf("-> %s\n", terminal_functions[i]);
}
printf("manual page will come in handy\n");
return (-1);
}

