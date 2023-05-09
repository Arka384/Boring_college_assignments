#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node* getnode(void);
void traverse(node *);
node* push(node *, int );
node* pop(node *);


int main()
{
    node** stacks;
	//node* stack = NULL;
    int n = 5;
	int choice = 0, stackChoice = 0, temp = 0, level = 0;

    printf("Enter the number of stack: ");
    scanf("%d", &n);
    stacks = (node**)malloc(sizeof(node*) * n);
	for(int i = 0; i < n; i++)
		stacks[i] = NULL;

	while(1) {
		if(level == 0) {
			printf("\nEnter which stack to use: ");
			scanf("%d", &stackChoice);
			if(stackChoice < 0 || stackChoice >= n) {
				printf("Invalid stack choice\n");
				continue;
			}
			level = 1;
		}

		printf("\n1->push, 2->pop, 3->display, 4->change stack, 5->exit");
		printf("\nYour choice: ");
		scanf("%d", &choice);
		switch(choice) {
		case 1:
			printf("\nEnter new node information: ");
			scanf("%d",&temp);
			stacks[stackChoice] = push(stacks[stackChoice], temp);
			break;
		case 2:
			stacks[stackChoice] = pop(stacks[stackChoice]);
			break;
		case 3:
			traverse(stacks[stackChoice]);
			break;
		case 4:
			level = 0;
			break;
		case 5:
			return 0;
		default:
			printf("\nInvalid option given");
		}
	}

	printf("\n");
}

node* push(node *head, int val)
{
	node *t,*t1;
	t1 = getnode();
	if(t1 == NULL) {
		printf("\nOverflow");
		return head;
	}
	t1->data = val;

	if(head == NULL) {
		head = t1;
		return head;
	}
	else
	{
		t = head;
		while(t->next != NULL)
			t = t->next;
		t->next = t1;
	}
	return head;
}

node* pop(node *head)
{
	if(head == NULL) {
		printf("\nStack Underflow\n");
		return head;
	}

	if(head->next == NULL) {
		node* t = head;
		head = head->next;
		free(t);
		return head;
	}

	node *t,*t1;
	t = head;
	while(t->next->next != NULL)
		t = t->next;
	t1 = t->next;
	t->next = NULL;
	printf("Popped value %d\n",t1->data);
	free(t1);
	return head;
}

node *getnode()
{
	node *t;
	t = (node*)malloc(sizeof(node));
	t->next = NULL;
	return t;
}

void traverse(node *head)
{
	node *t;
	if(head == NULL)
		printf("\nList is empty\n");
	else
	{
		t = head;
		printf("\nThe linked list is-> ");
		while(t != NULL)
		{
			printf("%d ",t->data);
			t = t->next;
		}
	}
}
