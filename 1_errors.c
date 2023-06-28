#include "main.h"

/**
 * get_error - A function that checks for any errors in a simple shell
 * @message: the argument to be parsed
 * Return: 0
 */
void get_error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
}

/**
 * exit_shell - A function that exits a simple shell
 * Return: 0
 */
void exit_shell() {
    exit(0);
}

