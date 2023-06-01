#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int is_prime(int n) {
    if (n < 2) {
        return 0;
    }

    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    pid_t pid[10];
    int start = 1;
    int end = 100000;
    int status;

    for (int i = 0; i < 10; i++) {
        pid[i] = fork(); // create a child process
        // waitpid(pid[i], &status, 0); // in synch but not parallel
        if (pid[i] == 0) { // child process
            for (int j = start; j <= end; j++) {
                if (is_prime(j)) {
                    printf("At process p%d --- %d",i+1, j);
                }
            }
            exit(0);
        }
        start += 100000;
        end += 100000;
    }

    for (int i = 0; i < 10; i++) { // parallel but not in synch
        waitpid(pid[i], &status, 0);
    }

    return 0;
}
