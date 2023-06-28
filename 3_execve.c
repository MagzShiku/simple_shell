#include "main.h"

void mj_execve(const char *mj_cmd, char **mj_arg, int mj_num_arg) {
    /* Check if the command exists in the PATH*/
    const char *mj_p1 = get_path(mj_cmd); /* Added missing declaration*/
	pid_t mj_pid;
	int mj_status;
	int exit_status;
	int mj_sig;
	(void)mj_num_arg;

    if (mj_p1 == NULL) {
        get_error("Command not found");
        return;
    }

    /* Fork a child process*/
    mj_pid = fork();
    if (mj_pid == -1) {
        perror("Fork failed");
        return;
    } else if (mj_pid == 0) {
        /* Child process*/
        /* Execute the command*/
        execv(mj_p1, mj_arg);
        fprintf(stderr, "Execution of command failed");
        exit(EXIT_FAILURE);
    } else {
        /* Parent process*/
        /* Wait for the child process to complete*/
        
        waitpid(mj_pid, &mj_status, 0);

        if (WIFEXITED(mj_status)) {
            /* Command executed successfully*/
            exit_status = WEXITSTATUS(mj_status);
            if (exit_status != 0) {
                printf("Command exited with status %d\n", exit_status);
            }
        } else if (WIFSIGNALED(mj_status)) {
            /* Command terminated by a signal*/
            mj_sig = WTERMSIG(mj_status);
            fprintf(stderr, "Command terminated by signal %d\n", mj_sig);
        }
    }
}

