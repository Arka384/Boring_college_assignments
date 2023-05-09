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
	FILE* file = fopen("q_2_input.txt", "r");
    int i;

    fscanf (file, "%d", &i);    
    while (!feof (file)) {  
        stack = push(stack, i);
        fscanf (file, "%d", &i);      
    }

    printf("The data in reverse order is:\n");
    traverse(stack);
    

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
	else {
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
        printf("%d, ",head->data);
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
	printf("%d, ",t1->data);
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
	while(head != NULL) {
        head = pop(head);
    }
}
