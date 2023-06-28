#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_INPUT_LENGTH 100

void get_error(const char* message);
void exit_shell();
void get_env(void);
const char *get_path(const char *command);
void mj_execve(const char *command, char **arg, int mj_num_arg);
const char *command_path(const char* command);
void execute_piped_commands(const char* command1, const char* command2);
void set_var(const char* name, const char* value);
const char* get_var(const char* name);
void execute_builtin_command(const char* command, char** arg, int num_arg);
int mjCopyFl(const char* source_file, const char* destination_file);
int mjListDir(const char* directory);
void mjPrintFile(const char* file_path);
void helpMeHere();

#endif /*MAIN*/
