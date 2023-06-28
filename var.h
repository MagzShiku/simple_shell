#ifndef VAR_H
#define VAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdio.h>

void set_var(const char* name, const char* value);
const char* get_var(const char* name);

#endif  // VAR_H

