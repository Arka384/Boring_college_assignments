#include <stdio.h>
#include <malloc.h>

typedef struct node{
	int data;
    int priority;
	struct node *next;
}node;

node* getnode(void);
node* insert(node* , int , int );
node* delete(node* );
void display(node *);

int main()
{
    node* head = NULL;
    int choice, data, p, x;
    while(1) {
		printf("\n1 -> insert, ");
		printf("2 -> delete, ");
		printf("3 -> Exit, ");
		printf("\nEnter choice: ");
		scanf("%d", &choice);

		switch(choice) {
		case 1:
			printf("\nEnter data to insert: ");
			scanf("%d", &data);
            printf("\nEnter priotity of data: ");
			scanf("%d", &p);
			head = insert(head, data, p);
			break;
		case 2:
            head = delete(head);
			break;
		case 3:
			return 0;
		default:
			printf("\nWrong choice");
		}
	}

	return 0;

}

node* delete(node* head) {
    if(head == NULL) {
        printf("Underflow\n");
        return head;
    }
    node* t = head;
    printf("deleted value %d\n", t->data);
    head = head->next;
    free(t);
    return head;
}

node* insert(node* head, int data, int p) {
    node* t = getnode();
    if(t == NULL) {
        printf("Overflow\n");
        return head;
    }
    t->data = data;
    t->priority = p;
    if(head == NULL) {
        head = t;
        return head;
    }
    if(head->priority > p) {
        t->next = head;
        head = t;
        return head;
    }
    node* temp = head;
    while(temp->next != NULL && temp->next->priority < t->priority)
        temp = temp->next;

    t->next = temp->next;
    temp->next = t;
    return head;
}


node *getnode() {
	node *t;
	t = (node*)malloc(sizeof(node));
	t->next = NULL;
	return t;
}

void display(node *head)
{
	node *t;
	if(head==NULL)
		printf("\nList is empty");
	else
	{
		t=head;
		printf("\nThe linked list is-> ");
		while(t!=NULL)
		{
			printf("%d ",t->data);
			t=t->next;
		}
	}
}