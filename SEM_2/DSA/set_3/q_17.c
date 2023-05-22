#include<stdio.h>
#include<malloc.h>

typedef struct node {
	int data;
    struct node *prev;
	struct node *next;
} node;

typedef struct Queue{
	struct node *front;
	struct node *rear;
}Queue;

Queue* createQueue(Queue *);
node* getnode(void);
void display(Queue* );
Queue* insertFront(Queue *, int );
Queue* insertBack(Queue *, int );
Queue* deleteFront(Queue *);
Queue* deleteBack(Queue *);



int main()
{
    int choice, data, x;
    Queue* queue;
    queue = createQueue(queue);

    while(1) {
		printf("\n1 -> push front, ");
		printf("\n2 -> push back, ");
		printf("\n3 -> pop fornt, ");
		printf("\n4 -> pop back, ");
		printf("\n5 -> display, ");
		printf("\n6 -> Exit, ");
		printf("\nEnter choice: ");
		scanf("%d", &choice);

		switch(choice) {
		case 1:
			printf("\nEnter data to insert: ");
			scanf("%d", &data);
			queue = insertFront(queue, data);
			break;
		case 2:
			printf("\nEnter data to insert: ");
			scanf("%d", &data);
            queue = insertBack(queue, data);
			break;
		case 3:
			queue = deleteFront(queue);
			break;
		case 4:
			queue = deleteBack(queue);
            break;
        case 5:
            display(queue);
            break;
        case 6:
            return 0;
		default:
			printf("\nWrong choice");
		}
	}

}

Queue* deleteBack(Queue *queue) {
    if(queue->rear == NULL) {
        printf("Queue underflow\n");
        return queue;
    }
    int data = queue->rear->data;
    printf("popped data: %d\n", data);
    queue->rear = queue->rear->prev;
    if(queue->rear != NULL)
        queue->rear->next = NULL;
    return queue;
}

Queue* deleteFront(Queue *queue) {
    if(queue->front == NULL) {
        printf("Queue underflow\n");
        return queue;
    }
    int data = queue->front->data;
    printf("popped data: %d\n", data);
    queue->front = queue->front->next;
    if(queue->front == NULL)
        queue->rear = NULL;
    else
        queue->front->prev = NULL;
    return queue;
}

Queue* insertBack(Queue *queue, int data) {
    node* t = getnode();
    if(t == NULL) {
        printf("Queue overflow\n");
        return queue;
    }
    t->data = data;
    if(queue->rear == NULL) {
        queue->front = t;
        queue->rear = t;
        return queue;
    }
    queue->rear->next = t;
    t->prev = queue->rear;
    queue->rear = t;
    return queue;
}

Queue* insertFront(Queue *queue, int data) {
    node* t = getnode();
    if(t == NULL) {
        printf("Queue overflow\n");
        return queue;
    }
    t->data = data;
    if(queue->rear == NULL) {
        queue->front = t;
        queue->rear = t;
        return queue;
    }
    t->next = queue->front;
    queue->front->prev = t;
    queue->front = t;
    return queue;
}

void display(Queue* queue) {
    if(queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("\n");
    node* t = queue->front;
    while(t != queue->rear->next) {
        printf("%d, ", t->data);
        t = t->next;
    }
}

Queue* createQueue(Queue *queue) {
    queue = (Queue*) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

node* getnode() {
    node *t;
	t = (node*)malloc(sizeof(node));
    t->prev = NULL;
	t->next = NULL;
	return t;
}