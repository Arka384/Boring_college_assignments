#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        printf("Child process - PID: %d, Parent PID: %d\n", getpid(), getppid());
        sleep(1);
        exit(50);
    }
    else {
        // Parent process
        printf("Parent process - PID: %d, Child PID: %d\n", getpid(), pid);
        wait(&status);
        printf("Child process exited with status: %d\n", WEXITSTATUS(status));
    }

    return 0;
}
