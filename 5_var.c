#include "main.h"

#define MAX_VARS 100

static char* mj_vars[MAX_VARS];

void set_var(const char* name, const char* value) {
    /*Find the existing variable*/
    int index = -1;
    int i;

    for (i = 0; i < MAX_VARS; i++) {
        if (mj_vars[i] != NULL && strncmp(name, mj_vars[i], strlen(name)) == 0) {
            index = i;
            break;
        }
    }

    /*Set the variable*/
    if (index != -1) {
        /*Variable already exists, replace its value*/
        free(mj_vars[index]);
        mj_vars[index] = strdup(value);
    } else {
        /* Variable doesn't exist, create a new one*/
        for (i = 0; i < MAX_VARS; i++) {
            if (mj_vars[i] == NULL) {
                mj_vars[i] = malloc(strlen(name) + strlen(value) + 2); /* +2 for '=' and '\0'*/
                sprintf(mj_vars[i], "%s=%s", name, value);
                break;
            }
        }
    }
}

const char* _get_var(const char* name) {
    /* Find the variable*/

	int i;
    for (i = 0; i < MAX_VARS; i++) {
        if (mj_vars[i] != NULL && strncmp(name, mj_vars[i], strlen(name)) == 0) {
            return strchr(mj_vars[i], '=') + 1; /* Return the value after '='*/
        }
    }

    return NULL; /*Variable not found*/
}

