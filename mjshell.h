#ifndef MJSHELL_H
#define MJSHELL_H

#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define MJ_DELIMITER " \t\r\n\a\""
extern char **environ;

void isInteractive(void);
void isNOTinteractive(void);
char *inputRead(void);
char **tokenizer(char *input);
int execveArgs(char **args);
int execNew(char **args);
char *strmRead(void);
int mjCommands(char **args);
int mjExit(char **args);
int mjEnvironment(char **args);
int mjHelp(char **args);

#endif /* MJSHELL_H */
