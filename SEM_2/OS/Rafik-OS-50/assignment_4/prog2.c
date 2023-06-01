// Write a C program which prints prime numbers between the range 1 to 10,00,000 by creating ten child
// processes and subdividing the task equally among all child processes, i.e., the first child should print prime
// numbers in the range 1 to 1,00,000, the second child in the range 1,00,001 to 2,00,000, ... The child processes
// must run in parallel and the parent process must wait until all the child processes finish.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

#define RANGE 100000
#define NUM_CHILDREN 10

bool is_prime(int number) {
    if (number < 2)
        return false;

    int sqrt_num = sqrt(number);
    for (int i = 2; i <= sqrt_num; i++) {
        if (number % i == 0)
            return false;
    }

    return true;
}

void print_primes(int start, int end) {
    for (int number = start; number <= end; number++) {
        if (is_prime(number))
            printf("%d ", number);
    }
    printf("\n");
}

int main() {
    pid_t pid;
    int status;

    for (int i = 0; i < NUM_CHILDREN; i++) {
        pid = fork(); // Create a child process

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            // Child process
            int start = (i * RANGE) + 1;
            int end = (i + 1) * RANGE;

            printf("Child process %d - PID: %d, Parent PID: %d\n", i+1, getpid(), getppid());
            printf("Printing prime numbers between %d and %d:\n", start, end);
            print_primes(start, end);

            exit(0); // Exit the child process
        }
    }

    // Parent process
    for (int i = 0; i < NUM_CHILDREN; i++) {
        wait(&status); // Wait for each child process to finish
        printf("Child process %d finished.\n", i+1);
    }

    return 0;
}
