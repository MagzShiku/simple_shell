#inclide "mjshell.h"

/**
 * isInteractive - checks interactivity of CLI
 * Return: void
 */

void isInteractive(void)
{
	char *input;
	char **args;
	int _status;

	_status = -1;

	do {
		printf("mjshell$ ");

		input = inputRead();	/*see file 9_inputRead.c*/
		args = tokenizer();	/*see file 12_tokenizer.c*/

		_status = execveArgs();	/*see file 1_execveArgs.c*/

		free(input);
		free(args);

		if (_status >= 0)
		{
			exit(_status);	
		}
	} while (status == -1);
}
