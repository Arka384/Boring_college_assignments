#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

sem_t writeM, readM;
int readerCount = 0;

void* writerProcess() {
	while(1) {
		sem_wait(&writeM);
		printf("Writer is writing\n");
		sleep(2);
		printf("Writing is done\n");	
		sem_post(&writeM);
		sleep(1);
	}
}

void* readerProcess() {
	while(1) {
		sem_wait(&readM);
		readerCount++;
		if(readerCount == 1)
			sem_wait(&writeM);
		sem_post(&readM);
		
		sleep(1);
		printf("Reading is performed: %d\n", readerCount);
		
		sem_wait(&readM);
		readerCount--;
		if(readerCount == 0)
			sem_post(&writeM);
		sem_post(&readM);
		sleep(1);
	}
}


int main()
{
	sem_init(&readM, 1, 1);
	sem_init(&writeM, 1, 1);
	
	pthread_t wr[5], re[5];
	int r[5], w[5], rn = 5, wn = 2;
	for(int i=0;i<rn;i++)
		r[i] = pthread_create(&re[i], NULL, readerProcess, NULL);
	for(int i=0;i<wn;i++)
		w[i] = pthread_create(&wr[i], NULL, writerProcess, NULL);
	
	
	for(int i=0;i<rn;i++)
		pthread_join(re[i], NULL);
	for(int i=0;i<wn;i++)
		pthread_join(wr[i], NULL);
}














