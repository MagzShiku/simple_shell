#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int token_input(char *input, char **args);
void free_tokens(char **args, int token_num);
void input_handler(char *mj_input);
void mj_execve(char **args);
void pipe_commands(char **com1, char **com2);
int pipe_checker(char *input, char **commands);
char *mj_path(char *mj_cmd);
int pipe_checker(char *input, char **commands);
int pipe_maker(int mjPipe[2]);
void mjExecutePipe(char **command, int mjPipe[2]);
void awaitingChildren(void);
void pipe_commands(char **com1, char **com2);

#endif /*MAIN_H*/
