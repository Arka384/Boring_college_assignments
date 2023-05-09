#include<stdio.h>
#include<malloc.h>
#include <stdbool.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node* getnode(void);
void traverse(node *);
node* push(node* , int );
bool isEqual(node *, node* );

int main()
{
	node* stack_1 = NULL;
    node* stack_2 = NULL;
    int choice, t;
    
    printf("Enter data in first stack:");
    while(1) {
		printf("\n1->push, 2->break");
		printf("\nYour choice: ");
		scanf("%d", &choice);
        if(choice == 1) {
            printf("\nEnter data: ");
            scanf("%d", &t);
            stack_1 = push(stack_1, t);
        }
        else
            break;
	}

    printf("Enter data in second stack:");
    while(1) {
		printf("\n1->push, 2->break");
		printf("\nYour choice: ");
		scanf("%d", &choice);
        if(choice == 1) {
            printf("\nEnter data: ");
            scanf("%d", &t);
            stack_2 = push(stack_2, t);
        }
        else
            break;
	}

    traverse(stack_1);
    traverse(stack_2);

    if(isEqual(stack_1, stack_2)) {
        printf("\nThe two stacks are equal");
    }
    else {
        printf("\nThe two stacks are not equal");
    }



	printf("\n");
}

bool isEqual(node* s1, node* s2) 
{
    if (s1 == NULL && s2 == NULL)
        return true;
    if (s1 == NULL || s2 == NULL)
        return false;
    if (s1->data != s2->data)
        return false;
    return isEqual(s1->next, s2->next);
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
		printf("\nThe stack is-> ");
		while(t != NULL)
		{
			printf("%d ",t->data);
			t = t->next;
		}
	}
}
