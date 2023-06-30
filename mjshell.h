#ifndef MJ_SHELL_H
#define MJ_SHELL_H

#define MJ_DELIM " \a\r\n\t\""



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

char **tknizer(char *input);
int execveMj_arg_s(char **mj_arg_s);
int mjExit(char **mj_arg_s);
int mjEnviron(char **mj_arg_s);
void isIinteractive(void);
void is_NotInteractive(void);
int execNew(char **mj_arg_s);
char *_Stream(void);
extern char **environ;
int cdDir(char **mj_arg_s);
int needHelp(char **mj_arg_s);
char *readInput(void);

#endif/* MJ_SHELL_H */
