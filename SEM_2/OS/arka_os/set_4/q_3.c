#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define BUFFERSIZE 50

int isPalindrome(char* data);


int main()
{
	char buffer[BUFFERSIZE] = " ";

	int pipe_1[2];	//0 -> read , 1 -> write
	int pipe_2[2];

	if(pipe(pipe_1) == -1)
		return 0;
	if(pipe(pipe_2) == -1)
		return 0;

	pid_t pid = fork();
	if(pid == -1)
		return 0;
	if(pid == 0) { 
		//child
		close(pipe_1[0]); // close read from pipe 1
        close(pipe_2[1]); // close write from pipe 2

        while(1) {
        	read(pipe_2[0], buffer, BUFFERSIZE);
        	if (strcmp(buffer, "quit") == 0)
                break;
           	
           	if(isPalindrome(buffer))
           		write(pipe_1[1], "Yes", 4);
           	else
           		write(pipe_1[1], "No", 3);	
        }

        close(pipe_1[1]);
        close(pipe_2[0]);
        exit(20);
	}
	else {	
		//parent
		close(pipe_1[1]); // close write from pipe 1
        close(pipe_2[0]); // close read from pipe 2

        while(1) {
        	printf("\nEnter a string: ");
        	fgets(buffer, BUFFERSIZE, stdin);
        	buffer[strcspn(buffer, "\n")] = '\0'; // make \n and make it null
        	//fputs(buffer, stdout);

        	if (strcmp(buffer, "quit") == 0) {
                write(pipe_2[1], buffer, BUFFERSIZE);
                break;
            }

            write(pipe_2[1], buffer, BUFFERSIZE);
            read(pipe_1[0], buffer, BUFFERSIZE);
            fputs(buffer, stdout);
        }

	}



}

int isPalindrome(char data[]) {
	int i, len;
    len = strlen(data);

    for (i = 0; i < len / 2; i++) {
        if (data[i] != data[len - i - 1])
            return 0;
    }
    return 1;
}