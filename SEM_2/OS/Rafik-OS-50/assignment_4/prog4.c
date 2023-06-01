// Write a C program which prints the following menu
// 1. ls
// 2. pwd
// 3. uname
// 4. exit
// When, the user provides an input, the parent process creates a child process [if user’s choice is between 1-3]
// and executes the corresponding command [use execv() system call]. The main process waits for the child to
// finish and displays the menu again. The parent process terminates if user’s choice is 4.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int choice = 0;
    while (choice != 4) {
        printf("1. ls\n");
        printf("2. pwd\n");
        printf("3. uname\n");
        printf("4. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            pid_t pid = fork();
            if (pid < 0) {
                perror("Fork failed");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {
                // Child process
                char* command;
                switch (choice) {
                    case 1:
                        command = "ls";
                        break;
                    case 2:
                        command = "pwd";
                        break;
                    case 3:
                        command = "uname";
                        break;
                }

                execlp(command, command, NULL);
                perror("Exec failed");
                exit(EXIT_FAILURE);
            } else {
                // Parent process
                int status;
                waitpid(pid, &status, 0);
                printf("\n");
            }
        } else if (choice != 4) {
            printf("Invalid choice. Please try again.\n\n");
        }
    }

    printf("Exiting program.\n");
    return 0;
}
