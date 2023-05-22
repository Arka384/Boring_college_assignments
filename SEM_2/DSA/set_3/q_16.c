#include <stdio.h>
#include <limits.h>
#define MAX 5

int queue[MAX] = {0};
int front = -1;
int rear = -1;

void display(void);
void insert(int );
int delete(void);

int main()
{
	int choice, data, x;
	while(1) {
		printf("\n1 -> insert, ");
		printf("2 -> delete, ");
		printf("3 -> display, ");
		printf("4 -> Exit, ");
		printf("\nEnter choice: ");
		scanf("%d", &choice);

		switch(choice) {
		case 1:
			printf("\nEnter data to insert: ");
			scanf("%d", &data);
			insert(data);
			break;
		case 2:
			x = delete();
			if(x != INT_MAX)
				printf("\nPopped data is %d", x);
			break;
		case 3:
			display();
			break;
		case 4:
			return 0;
		default:
			printf("\nWrong choice");
		}

	}

	return 0;
}

void display() {
	// if(rear == -1) {
	// 	printf("\nQueue is empty");
	// 	return;
	// }
	printf("\nQueue contents are:\n");
	// for(int i=front;i<=rear;i++) {
	// 	printf("%d, ", queue[i]);
	// }
    for(int i=0;i<MAX;i++) {
		printf("%d, ", queue[i]);
	}
	printf("\n");
}

int delete() {
	if(front == -1) {
		printf("\nUnderflow");
		return INT_MAX;
	}

	int d = queue[front];
    queue[front] = 0;
	if(front == rear) {
		front = rear = -1;
		return d;
	}
	else
		front = (front + 1) % MAX;
	return d;
}

void insert(int data) {
	if((rear + 1) % MAX == front) {
		printf("\nOverflow\n");
		return;
	}
	if(front == -1 && rear == -1)
		front = rear = 0;
	else
		rear = (rear + 1) % MAX;
	queue[rear] = data;
}