#include <stdio.h>
#include <malloc.h>
#include <limits.h>

typedef struct node{
	int data;
	struct node *next;
}node;
node* stack_1 = NULL;
node* stack_2 = NULL;

typedef struct Queue{
	struct node *front;
	struct node *rear;
}Queue;

node* getnode(void);
Queue* create(Queue* );
Queue* insert(Queue* , int );
int delete(Queue* );
void display(Queue* );
Queue* replace(Queue* , int , int);

void push(int, node** );
int pop(node** );

int main()
{
    Queue* queue;
    int choice, data, x;
    queue = create(queue);
   
	while(1) {
		printf("\n1 -> insert, ");
		printf("2 -> delete, ");
		printf("3 -> display, ");
		printf("4 -> replace q with x, ");
		printf("5 -> Exit, ");
		printf("\nEnter choice: ");
		scanf("%d", &choice);

		switch(choice) {
		case 1:
			printf("\nEnter data to insert: ");
			scanf("%d", &data);
			queue = insert(queue, data);
			break;
		case 2:
			x = delete(queue);
			if(x != INT_MIN)
				printf("\nPopped data is %d", x);
			break;
		case 3:
			display(queue);
			break;
        case 4:
            printf("\nEnter target data: ");
			scanf("%d", &data);
            printf("\nEnter data to replace: ");
			scanf("%d", &x);
            queue = replace(queue, data, x);
            break;
		case 5:
			return 0;
		default:
			printf("\nWrong choice");
		}
	}

	return 0;

}

Queue* replace(Queue* queue, int t, int v) {
    if(queue->front == NULL) {
        printf("\nQueue is empty");
        return queue;
    }
    while(queue->front != NULL) {
        int x = delete(queue);
        if(x == t)
            x = v;
        push(x, &stack_1);
    }
    while(stack_1 != NULL)
        push(pop(&stack_1), &stack_2);
    while(stack_2 != NULL)
        queue = insert(queue, pop(&stack_2));
    return queue;
}

Queue* insert(Queue* queue, int val) {
    node* t = getnode();
    if(t == NULL) {
        printf("\nQueue overflow");
        return queue;
    }
    t->data = val;
    if(queue->rear == NULL) {
        queue->front = t;
        queue->rear = t;
        return queue;
    }
    queue->rear->next = t;
    queue->rear = t;
    return queue;
}

int delete(Queue* queue) {
    if(queue->front == NULL) {
        printf("Queue underflow\n");
        return INT_MIN;
    }
    int data = queue->front->data;
    queue->front = queue->front->next;
    if(queue->front == NULL)
        queue->rear = NULL;
    return data;
}

void push(int val, node** stack) {
	node* t;
	t = getnode();
	t->data = val;
	t->next = *stack;
	*stack = t;
}

int pop(node** stack) {
    int c = INT_MAX;
    if(*stack == NULL) {
		printf("\nStack Underflow\n");
        return c;
    }
    node* t = *stack;
    c = t->data;
    *stack = (*stack)->next;
    free(t);
    return c;
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

Queue* create(Queue* queue) {
    queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

node *getnode() {
	node *t;
	t = (node*)malloc(sizeof(node));
	t->next = NULL;
	return t;
}
