#include "mjshell.h"

/**
 * isNOTinteractive - the shell not beig interractive
 * Return: void
 */

void isNOTinteractive(void)
{
	int _status;
	char *input;
	char **args;

	_status = -1;  /*this function is related to 3_is_interactive.c*/

	do {
		_status = execveArgs(args); /*see file 1_execveArgs.c*/
		args = tokenizer(input);     /*see file 12_tokenizer.c*/
		input = strmRead();    /*see file 9_inputRead.c*/

		free(input);
		free(args);

		if (_status >= 0)
		{
			exit(_status);
		}
	} while (_status == -1);

}
