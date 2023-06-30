#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MJ_TOK_DELIM " \r\t\a\n\""
void shell_no_interactive(void);
void shell_interactive(void);
char *read_line(void);
char *read_stream(void);
int mj_cd(char **mj_args);
int mj_exit(char **mj_args);
int mj_env(char **mj_args);
int mj_help(char **mj_args);
char **split_line(char *mj_line);
int execute_args(char **mj_args);
int mj_new_process(char **mj_args);
extern char **environ;
#endif/******SHELL_H******/
