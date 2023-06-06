#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

int turn = 1;

int main()
{
	key_t key = ftok("file", 25);	//generate unique key
	int shmId = shmget(key, 1024, 0666 | IPC_CREAT);	//create shared memory with that key
	char* buffer = (char*) shmat(shmId, NULL, 0);	//attach shared memory to process workspace data
	int turn = 0;	//0 -> parent, 1 -> child
	sprintf(buffer, "%d", turn);	//turn is from first location to +4 location in buffer
	
	srand(time(NULL));	//reset time seed
	
	pid_t pid = fork();
	if(pid == -1) {
		printf("\nFork failed");
		return 0;
	}
	
	if(pid == 0) {	//child
		while(turn != 1)
			sscanf(buffer, "%d", &turn);
			
		int max = INT_MIN;
		int min = INT_MAX;
		int data;
		printf("\nRead from child: \n");
		for(int i=1;i<=100;i++) {
			sscanf(buffer + (4*i), "%d", &data);
			printf("%d, ", data);
			max = (data > max) ? data : max;
			min = (data < min) ? data : min;
		}
		printf("\n");
		sprintf(buffer + (4 * 101), "%d", max);
		sprintf(buffer + (4 * 102), "%d", min);
		
		turn = 0;
		sprintf(buffer, "%d", turn);
	}
	else {	//parent
		while(turn != 0)
			sscanf(buffer, "%d", &turn);
		
		printf("Parent is generating 100 random integers... \n");
		for(int i=1;i<=100;i++) {
			int temp = rand() % 500 + 1;
			sprintf(buffer + (4*i), "%d", temp);
		}
		printf("Parent wrote in buffer\n");
		
		//now parent gave access to child for calculation
		turn = 1;
		sprintf(buffer, "%d", turn);
		
		//now wait until child finishes calculation 
		while(turn != 0)
			sscanf(buffer, "%d", &turn);
		
		int max = 0, min = 0;
		sscanf(buffer + (4 * 101), "%d", &max);
		sscanf(buffer + (4 * 102), "%d", &min);
		
		printf("Max = %d, Min = %d\n", max, min);
		
		
		wait(NULL);
	}
	
	
	shmdt(buffer);
	shmctl(shmId, IPC_RMID, NULL);
	return 0;
}













