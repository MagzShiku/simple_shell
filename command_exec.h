#ifndef COM_H
#define COM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdio.h>

void mj_execve(const char *command, char **arg, int num_arg);
const char *command_path(const char* command);

#endif  // COMMAND_EXECUTION_H

