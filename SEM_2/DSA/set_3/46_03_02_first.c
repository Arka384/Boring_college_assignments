#include<stdio.h>
#define MAX 100
int stack[MAX] = {0};
int top = -1;

void push(int val, int n);
void pop(void);
void traverse(void);

int main()
{
	
	int n = 0;
	printf("\nEnter the size of the stack: ");
	scanf("%d", &n);

	int choice = 0;
	int temp = 0;

	while(1) {
		printf("\n1->push, 2->pop, 3->display, 4->exit");
		printf("\nYour choice: ");
		scanf("%d", &choice);
		switch(choice) {
		case 1:
			printf("\nEnter new data: ");
			scanf("%d",&temp);
			push(temp, n);
			break;
		case 2:
			pop();
			break;
		case 3:
			traverse();
			break;
		case 4:
			return 0;
		default:
			printf("\nInvalid option given");
		}
	}

	printf("\n");
}

void push(int val, int n)
{
	if(top == n-1) {
		printf("\nStack overflow\n");
		return;
	}
	top++;
	stack[top] = val;
}

void pop()
{
	if(top == -1) {
		printf("\nStack underflow\n");
		return;
	}
	printf("\nPopped element is %d\n", stack[top]);
	top--;
}

void traverse()
{
	if(top == -1) {
		printf("\nStack Empty\n");
		return;
	}
	printf("\nStack elements are: ");
	for(int i=0;i<=top;i++)
		printf("%d, ", stack[i]);
	printf("\n");
}
