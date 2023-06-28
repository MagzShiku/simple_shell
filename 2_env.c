#include "main.h"
#include <unistd.h>

extern char **environ;

void get_env(void) {
    char **mj_env;

    mj_env= environ;

    while (*mj_env != NULL) {
        printf("%s\n", *mj_env);
        mj_env++;
    }
}

const char *get_path(const char *command) {
	    const char* mj_path;
    char *mj_token;
    char mj_p1[1024];
	
	
	mj_path = getenv("PATH");
    if (mj_path == NULL) {
        get_error("PATH environment variable not set");
        return NULL;
    }

    mj_token = strtok((char*)mj_path, ":");
    while (mj_token != NULL) {
        
        snprintf(mj_p1, sizeof(mj_p1), "%s/%s", mj_token, command);

        if (access(mj_p1, X_OK) == 0) {
            return strdup(mj_p1);
        }

        mj_token = strtok(NULL, ":");
    }

    return NULL;
}

