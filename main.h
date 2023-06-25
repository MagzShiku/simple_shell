#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void mj_execve(char **args);
char *mj_path(char *mj_cmd);
int token_input(char *input, char **args);
void free_tokens(char **args, int token_num);

#endif /*MAIN_H*/
