#include "main.h"


void execute_builtin_command(const char* command, char** arg, int num_arg) {
    int i;
    char cwd[1024];
	
	if (strcmp(command, "exit") == 0) {
        /* Exit the shell */
        exit_shell();
    } else if (strcmp(command, "env") == 0) {
        /* Print the current environment */
        get_env();
    } else if (strcmp(command, "cd") == 0) {
        /* Change directory */
        if (num_arg > 1) {
            if (chdir(arg[1]) != 0) {
                get_error("Failed to change directory");
            }
        } else {
            get_error("Missing argument for cd command");
        }
    } else if (strcmp(command, "pwd") == 0) {
        /* Print working directory */
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("Current working directory: %s\n", cwd);
        } else {
            get_error("Failed to get current working directory");
        }
    } else if (strcmp(command, "echo") == 0) {
        /* Print arguments */
        for (i = 1; i < num_arg; i++) {
            printf("%s ", arg[i]);
        }
        printf("\n");
    } else if (strcmp(command, "mkdir") == 0) {
        /* Create directory */
        if (num_arg > 1) {
            if (mkdir(arg[1], 0777) != 0) {
                get_error("Failed to create directory");
            }
        } else {
            get_error("Missing argument for mkdir command");
        }
    } else if (strcmp(command, "rmdir") == 0) {
        /* Remove directory */
        if (num_arg > 1) {
            if (rmdir(arg[1]) != 0) {
                get_error("Failed to remove directory");
            }
        } else {
            get_error("Missing argument for rmdir command");
        }
    } else if (strcmp(command, "rm") == 0) {
        /* Remove file */
        if (num_arg > 1) {
            if (remove(arg[1]) != 0) {
                get_error("Failed to remove file");
            }
        } else {
            get_error("Missing argument for rm command");
        }
    } else if (strcmp(command, "cp") == 0) {
        /* Copy file */
        if (num_arg > 2) {
            if (mjCopyFl(arg[1], arg[2]) != 0) {
                get_error("Failed to copy file");
            }
        } else {
            get_error("Missing arguments for cp command");
        }
    } else if (strcmp(command, "mv") == 0) {
        /* Move file */
        if (num_arg > 2) {
            if (rename(arg[1], arg[2]) != 0) {
                get_error("Failed to move file");
            }
        } else {
            get_error("Missing arguments for mv command");
        }
    } else if (strcmp(command, "ls") == 0) {
        /* List directory contents */
        if (num_arg > 1) {
            mjListDir(arg[1]);
        } else {
            mjListDir(".");
        }
    } else if (strcmp(command, "cat") == 0) {
        /* Concatenate and print files */
        if (num_arg > 1) {
            for (i = 1; i < num_arg; i++) {
                mjPrintFile(arg[i]);
            }
        } else {
            get_error("Missing arguments for cat command");
        }
    } else if (strcmp(command, "help") == 0) {
        /* Print help message */
        helpMeHere();
    } else {
        /* Command not found */
        get_error("Command not found");
    }
}

