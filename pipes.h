#ifndef PIPING_H
#define PIPING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdio.h>

void execute_piped_commands(const char* command1, const char* command2);

#endif  // PIPING_H

