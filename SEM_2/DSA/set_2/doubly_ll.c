#include<stdio.h>
#include<malloc.h>

typedef struct node {
	int data;
    struct node *prev;
	struct node *next;
} node;

node* getnode(void);
node* create(node* );
void display(node* );
node* insbeg(node* , int );
node* insend(node* , int );
node* insAfterK(node* , int , int );
node* insAfterNode(node* , int , int );
node* insBeforeK(node* , int , int );
node* insBeforeNode(node* , int , int );

node* delbeg(node* );
node* delend(node* );
node* delAfterK(node* , int );
node* delBeforeK(node* , int );
node* delKNode(node* , int );
node* delValue(node* , int );

int main()
{
    node* head = NULL;
    head = create(head);

	head = delValue(head, 10);

	head = insend(head, 20);
	//head = delKNode(head, 2);
	head = insend(head, 30);
	head = insend(head, 40);
	display(head);
	head = delValue(head, 40);
    
	display(head);


}

node* getnode()
{
    node *t;
	t=(node*)malloc(sizeof(node));
    t->prev = NULL;
	t->next = NULL;
	return t;
}

node* create(node* head)
{
	node* t = getnode();
	printf("\nEnter first node information: ");
	scanf("%d", &t->data);
	head = t;
	return head;
}

void display(node* head)
{
	node *t;
	if(head == NULL) {
		printf("\nList is empty");
        return;
    }
	t = head;
	printf("\nThe linked list is-> ");
	while(t != NULL) {
		printf("%d ",t->data);
		t = t->next;
	}
}

node* insbeg(node* head, int val)
{
	node *t;
	t = getnode();
	t->data = val;
	t->next = head;
    if(head != NULL)
        head->prev = t;
	head = t;
	return head;
}

node* insend(node* head, int val)
{
	node *t, *t1;
	t=getnode();
	t->data = val;
    if(head == NULL) {
        head = t;
        return head;
    }
	t1=head;
	while(t1->next!=NULL)
		t1 = t1->next;
	t1->next = t;
    t->prev = t1;
	return head;
}

node* insAfterK(node* head, int k, int val)
{
	node *t, *t1;
	if(head == NULL) {
		printf("\nList is empty");
		return head;
	}
	t = head;
    int i = 1;
    while(i < k && t->next != NULL) {
        t = t->next;
        i++;
    }
    if( (i != k && t->next == NULL) || k <= 0) {
        printf("\nInvalid index given");
        return head;
    }

	t1=getnode();
    t1->data = val;    
    t1->next = t->next;
    t->next = t1;
    t1->prev = t;
    if(t1->next != NULL)
        t1->next->prev = t1;
	return head;
}

node* insAfterNode(node* head, int target_val, int val)
{
	node *t, *t1;
	if(head == NULL) {
		printf("\nList is empty");
		return head;
	}
	t = head;
    while(t->data != target_val && t->next != NULL)
        t = t->next;
    if(t->data != target_val && t->next == NULL) {
        printf("\nInvalid value given");
        return head;
    }

	t1=getnode();
    t1->data = val;    
    t1->next = t->next;
    t->next = t1;
    t1->prev = t;
    if(t1->next != NULL)
        t1->next->prev = t1;
	return head;
}

node* insBeforeK(node* head, int k, int val)
{
	if(head == NULL) {
		printf("\nList is empty");
		return head;
	}
    if(k <= 0) {
        printf("\nInvalid location given");
		return head;
    }
    if(k == 1) {
        head = insbeg(head, val);
        return head;
    }
    
    head = insAfterK(head, k-1, val);
	return head;
}

node* insBeforeNode(node* head, int target_val, int val)
{
	node *t, *t1;
	if(head == NULL) {
		printf("\nList is empty");
		head = create(head);
		return head;
	}
    if(head->data == target_val) {
        head = insbeg(head, val);
        return head;
    }

	t = head;
    while(t->next != NULL && t->next->data != target_val)
        t = t->next;
    if(t->next == NULL) {
        printf("\nInvalid value given");
        return head;
    }

    t1=getnode();
    t1->data = val;    
    t1->next = t->next;
    t->next = t1;
    t1->prev = t;
    if(t1->next != NULL)
        t1->next->prev = t1;
	return head;
}

node* delbeg(node* head)
{
	if(head == NULL) {
		printf("\nList is empty");
		return head;
	}
	node *t;
	t = head;
	head = head->next;
	if(head != NULL)
		head->prev = NULL;
	printf("\nDeleted value %d",t->data);
	free(t);
	return head;
}

node* delend(node* head)
{
	if(head == NULL) {
		printf("\nList is empty");
		return head;
	}

	node *t, *newLast;
	t = head;
	if(head->next == NULL) {
		printf("\nDeleted value %d",head->data);
		head = NULL;
		free(t);
		return head;
	}
	
	while(t->next != NULL)
		t = t->next;
	newLast = t->prev;
	newLast->next = NULL;
	printf("\nDeleted value %d",t->data);
	free(t);
	return head;
}

node* delAfterK(node* head, int k)
{
	node *t, *t1;
	if(head == NULL) {
		printf("\nList is empty");
		return head;
	}
	t = head;
    int i = 1;
    while(i < k && t->next != NULL) {
        t = t->next;
        i++;
    }
    if((t->next == NULL) || k <= 0) {
        printf("\nInvalid index given");
        return head;
    }
	//now delete after t
	t1 = t->next;
	t->next = t->next->next;
	if(t->next != NULL)
		t->next->prev = t;
	printf("\nDeleted value %d",t1->data);
	free(t1);
	return head;
}

node* delBeforeK(node* head, int k)
{
	if(head == NULL) {
		printf("\nList is empty");
		return head;
	}
    if(k <= 1) {
        printf("\nInvalid location given");
		return head;
    }
	if(k == 2) {
		head = delbeg(head);
		return head;
	}
    
    head = delAfterK(head, k-2);
	return head;
}

node* delKNode(node* head, int k)
{
	if(head == NULL) {
		printf("\nList is empty");
		return head;
	}
	if(k <= 0) {
		printf("\nInvalid location given");
		return head;
	}
	if(k == 1) {
		head = delbeg(head);
		return head;
	}

	head = delAfterK(head, k-1);
	return head;	
}

node* delValue(node* head, int val)
{
	if(head == NULL) {
		printf("\nList is empty");
		return head;
	}

	node *t, *t1;
	t = head;
	if(head->data == val) {
		head = delbeg(head);
		return head;
	}

	while(t->next != NULL && t->next->data != val)
			t = t->next;
	if(t->next == NULL) {
		printf("\nValue not present");
		return head;
	}

	t1 = t->next;
	t->next = t->next->next;
	if(t->next != NULL)
		t->next->prev = t;
	printf("\nDeleted value %d",t1->data);
	free(t1);

	return head;
}