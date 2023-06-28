#include "main.h"
/** 
* mjcmdHandling- A function that handles builtin functions in a simple shell
* @str_mj: the parsed strings inserted
* Return:0
*/
int mjcmdHandling(char **str_mj)
{
	int Cmds_num = 1024;
	int mj;
	int switchmjArgs; 
	char* mjCmd[Cmds_num];
	char* USER;


	mjCmd[0] = "exit";
	mjCmd[1] = "cd";
	mjCmd[2] = "hello";
	mjCmd[3] = "setenv";
	mjCmd[4] = "unsetenv";

	mj = 0;

	switchmjArgs = 0;

	while (mj < Cmds_num)
	{
		if (strcmp(str_mj[0], mjCmd[mj]) == 0)
		{
			switchmjArgs = mj + 1;
			break;
		}
		mj++;
	}

	switch (switchmjArgs)
	{
		case 1:
			fprintf(stdout, "\n\nIt's a wrap from mj_shell\n");
			exit(0);
		case 2:
			if (str_mj[1] != NULL)
			{
				chdir(str_mj[1]);
				return 1;
			}
			else
			{
				fprintf(stderr, "Please specify a directory to change to\n");
				return 0;
			}

		case 3:
			USER = getenv("USER");
			fprintf(stdout, "\n\n How are you doing today %s.\n Thank you for visiting this shell. Only use it for educational purposes"
					"\n\nWe are yet to update the terms and conditions, as well as the HELP ME page\n"
					"\n\n stay tuned\n",
					USER);
			return 1;

		case 4:
			if (str_mj[1] != NULL)
			{
				int mj_2 = setenv(str_mj[1], str_mj[2], 1);
				if (mj_2 != 0) {
					fprintf(stderr, "\n\nFailed to set environment variable %s\n", str_mj[1]);
					return 0;
				}
				return 1;
			} 
			else
			{
				fprintf(stderr, "\n\nPlease specify a variable name and value to set\n");
				return 0;
			}

		case 5:
			if (str_mj[1] != NULL)
			{
				int mj_2 = unsetenv(str_mj[1]);
				if (mj_2 != 0) {
					fprintf(stderr, "\n\nFailed to unset environment variable %s\n", str_mj[1]);
					return 0;
				}
				return 1;
			}
			else
			{
				fprintf(stderr, "\n\nPlease specify a variable name to unset\n");
				return 0;
			}

		default:
			break;
	}
	return (0);
}
