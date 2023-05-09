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
	node* stack = NULL;
	int choice = 0;
	int temp = 0;

	while(1) {
		printf("\n1->push, 2->pop, 3->display, 4->exit");
		printf("\nYour choice: ");
		scanf("%d", &choice);
		switch(choice) {
		case 1:
			printf("\nEnter new node information: ");
			scanf("%d",&temp);
			stack = push(stack, temp);
			break;
		case 2:
			stack = pop(stack);
			break;
		case 3:
			traverse(stack);
			break;
		case 4:
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
