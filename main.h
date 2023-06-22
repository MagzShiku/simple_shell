#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

char *mj_input_copy_fn(const char *mj_input);
void mj_execve(char *argv[]);
char *mj_path(char *mj_cmd);

#endif /*MAIN_H*/
