#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *mj_input_copy_fn(const char *mj_input);
void mj_execve(char *argv[]);

#endif /*MAIN_H*/
