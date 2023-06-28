#include "main.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void exit_shell();
void get_env();
void execute_piped_commands(const char *command1, const char *command2);
void execute_builtin_command(const char *command, char **arg, int num_arg);
void mj_execve(const char *mj_cmd, char **mj_arg, int mj_num_arg);
void get_error(const char* message);
int mjCopyFl(const char* source_file, const char* destination_file);
int mjListDir(const char* directory);
void mjPrintFile(const char* file_path);
void helpMeHere();

int main() {
    char input[MAX_INPUT_LENGTH];
    char *token;
    char *command;
    char **arg;
    int num_arg;

    /* Main shell loop*/
    while (1) {
        /* Print the shell prompt*/
        printf("mjshell$ ");

        /* Read user input*/
        if (fgets(input, sizeof(input), stdin) == NULL) {
            get_error("Failed to read input");
            continue;
        }

        /* Remove trailing newline character*/
        input[strcspn(input, "\n")] = '\0';

        /* Parse the input*/
        token = strtok(input, " ");
        command = token;
        arg = NULL;
        num_arg = 0;

        /* Extract command and arguments*/
        while (token != NULL) {
            arg = realloc(arg, (num_arg + 1) * sizeof(char*));
            arg[num_arg] = token;
            num_arg++;

            token = strtok(NULL, " ");
        }

        /* Execute the command*/
        if (command != NULL) {
            if (strcmp(command, "exit") == 0) {
                /* Exit the shell*/
                exit_shell();
            } else if (strcmp(command, "env") == 0) {
                /* Print the current environment*/
                get_env();
            } else if (strcmp(command, "pipe") == 0) {
                /* Execute piped commands*/
                if (num_arg >= 3) {
                    execute_piped_commands(arg[1], arg[2]);
                } else {
                    get_error("Invalid usage of pipe command");
                }
            } else {
                /* Check for built-in commands*/
                execute_builtin_command(command, arg, num_arg);

                /* If not a built-in command, execute using mj_execve*/
                mj_execve(command, arg, num_arg);
            }
        }

        /* Clean up and free resources*/
        free(arg);
    }

    return 0;
}

