#include "shell.h"

/**
 * mj_execute_args - A function tha determines if a command is a builtin
 * or a process
 * @mj_args: This is a command and its flags
 * Return: 1 on sucess, 0 otherwise
 */
int mj_execute_args(char **mj_args)
{
	char *mj_builtin_func_list[] =
	{
		"env",
		"help",
		"cd",
		"exit"
	};
	int (*mj_builtin[])(char **) = {
		&mj_env,
		&mj_help,
		&mj_cd,
		&mj_exit
	};
	long unsigned int mj = 0;

	if (mj_args[0] == NULL)
	{
		return (-1);
	}
	for (; mj < sizeof(mj_builtin_func_list) / sizeof(char *); mj++)
	{
		if (strcmp(mj_args[0], mj_builtin_func_list[mj]) == 0)
		{
			return ((*mj_builtin[mj])(mj_args));
		}
	}
	return (mj_new_process(mj_args));
}
