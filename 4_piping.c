#include "main.h"

void execute_piped_commands(const char *mj_cmd1, const char *mj_cmd2) {
    int mj_pipe[2];
    pid_t mj_pid1, mj_pid2;

    /* Create pipe */
    if (pipe(mj_pipe) == -1) {
        fprintf(stderr, "Pipe creation failed");
        return;
    }

    /* Fork first child process */
    mj_pid1 = fork();
    if (mj_pid1 == -1) {
        fprintf(stderr, "Fork failed");
        return;
    } else if (mj_pid1 == 0) {
        /* Child process 1 */
        /* Replace stdout with write end of the pipe */
        close(mj_pipe[0]);
        dup2(mj_pipe[1], STDOUT_FILENO);
        close(mj_pipe[1]);
        /* Execute first command */
        execlp("/bin/sh", "/bin/sh", "-c", mj_cmd1, NULL);
        fprintf(stderr, "Execution of command 1 failed");
        exit(EXIT_FAILURE);
    }

    /* Fork second child process */
    mj_pid2 = fork();
    if (mj_pid2 == -1) {
        fprintf(stderr, "Fork failed");
        return;
    } else if (mj_pid2 == 0) {
        /* Child process 2 */
        /* Replace stdin with read end of the pipe */
        close(mj_pipe[1]);
        dup2(mj_pipe[0], STDIN_FILENO);
        close(mj_pipe[0]);
        /* Execute second command */
        execlp("/bin/sh", "/bin/sh", "-c", mj_cmd2, NULL);
        fprintf(stderr, "Execution of command 2 failed");
        exit(EXIT_FAILURE);
    }

    /* Close pipe ends in parent process */
    close(mj_pipe[0]);
    close(mj_pipe[1]);

    /* Wait for child processes to complete */
    waitpid(mj_pid1, NULL, 0);
    waitpid(mj_pid2, NULL, 0);
}

