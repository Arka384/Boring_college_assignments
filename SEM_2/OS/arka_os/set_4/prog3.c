#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 64
int checkPalindrome(char str[]);

int main() {
    
    char buffer[BUFFER_SIZE];

    int pipe1[2]; // child => parent communication
    int pipe2[2]; // parent => child communication
    
    if (pipe(pipe1) == -1) {return 1;}
    if (pipe(pipe2) == -1) {return 2;}

    pid_t pid = fork();

    if(pid == -1) {return 3;};

    if (pid == 0){
        //child
        close(pipe1[0]); // close read from pipe 1
        close(pipe2[1]); // close write from pipe 2

        while (1){
            read(pipe2[0], buffer, BUFFER_SIZE);

            if (strcmp(buffer, "quit") == 0) {
                break;
            }

            if(checkPalindrome(buffer)){
                write(pipe1[1], "Yes", 4);
            }else{
                write(pipe1[1], "No", 3);
            }
            
        }
        close(pipe1[1]);
        close(pipe2[0]);
        printf("\nChild processes terminated\n");
        exit(20);
    }else{
        //parent
        close(pipe1[1]); // close write from pipe 1
        close(pipe2[0]); // close read from pipe 2

        while (1){
            printf("\nEnter string ( for exit 'quit' ) :\n");
            fgets(buffer, BUFFER_SIZE, stdin);
            buffer[strcspn(buffer, "\n")] = '\0'; // make \n and make it null
            
            if (strcmp(buffer, "quit") == 0) {
                write(pipe2[1], buffer, BUFFER_SIZE);
                break;
            }

            write(pipe2[1], buffer, BUFFER_SIZE);

            read(pipe1[0], buffer, BUFFER_SIZE);
            printf("\nIs palindrome?: %s", buffer);
        }

        close(pipe1[0]);
        close(pipe2[1]);
        wait(NULL);
        printf("\nParent processes terminated\n");
        exit(19);
    }

    return 0;
}

int checkPalindrome(char str[])
{
    int i, len;
    len = strlen(str);

    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}
