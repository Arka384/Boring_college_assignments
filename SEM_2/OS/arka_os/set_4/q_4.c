#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int choice = 0;
	while(1) {
		printf("1. ls\n");
        printf("2. pwd\n");
        printf("3. uname\n");
        printf("4. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 3) {
        	pid_t pid = fork();
        	if(pid < 0) {
        		printf("\nFork failed");
        		exit(1);
        	}
        	else if(pid == 0) {
        		//child
        		char *command;
        		switch(choice) {
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
        		printf("error");
        		exit(EXIT_FAILURE);
        	}
        	else {
        		//parent
        		int status;
                waitpid(pid, &status, 0);
                printf("\n");
        	}

        }
      	else if(choice == 4) {
      		return 0;
      	}
      	else {
      		printf("\nInvalid option\n");
      		continue;
      	}

	}
}