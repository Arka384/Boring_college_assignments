// Write a C program to create a child process. The parent process must wait until the child finishes. Both
// the processes must print their own pid and parent pid. Additionally the parent process should print the exit
// status of the child.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;

    pid = fork(); // Create a child process

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process - PID: %d, Parent PID: %d\n", getpid(), getppid());
        // Perform child process operations here
        sleep(3); // Sleep for 3 seconds to simulate some work
        exit(50); // Exit the child process with status 42
    } else {
        // Parent process
        printf("Parent process - PID: %d, Child PID: %d\n", getpid(), pid);
        wait(&status); // Wait for the child process to finish
        printf("Child process exited with status: %d\n", WEXITSTATUS(status));
    }

    return 0;
}
