#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

sem_t full, empty, mutex;

void* producer() {
	int item = 1;
	while(1) {
		sem_wait(&empty);	//decrement empty
		sem_wait(&mutex);	
		sleep(1);
		printf("Produced item %d\n", item);
		item++;
		sem_post(&mutex);
		sem_post(&full);	//increment full
	}
}

void* consumer() {
	int item = 1;
	while(1) {
		sem_wait(&full);	//decrement full
		sem_wait(&mutex);
		sleep(1);
		printf("Consumed an item %d\n", item);
		item++;
		sem_post(&mutex);
		sem_post(&empty);	//increment empty
	}
}


int main()
{
	sem_init(&full, 0, 0);
	sem_init(&empty, 0 ,10);
	sem_init(&mutex, 0, 1);
	
	pthread_t prod, con;
	int p, c;
	p = pthread_create(&prod, NULL, producer, NULL);
	c = pthread_create(&con, NULL, consumer, NULL);
	
	
	pthread_join(prod, NULL);
	pthread_join(con, NULL);

}












