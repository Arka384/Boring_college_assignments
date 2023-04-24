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

node* reverse(node* );

void getInput(int* , int* , int* , int , int , int );

int main()
{
    node* head = NULL;
    int s, val, t_val, k;
	head = create(head);

	/*
		2 -> display, 3 -> ins front, 4 -> ins end
		5 -> ins after k'th, 6 -> ins after node,
		7 -> ins before k'th, 8 -> ins before node,

		9 -> del first, 10 -> del last
		11 -> del after k'th, 12 -> del before k'th
		13 -> del k'th, 14 -> del value

		15 -> reverse
	*/

	while(1)
	{
		// printf("2 -> display \n3 -> ins front \n4 -> ins end ");
		// printf("\n5 -> ins after k'th \n6 -> ins after node");
		// printf("\n7 -> ins before k'th \n8 -> ins before node");
		// printf("\n9 -> del first \n10 -> del last");
		// printf("\n11 -> del after k'th \n12 -> del before k'th");
		// printf("\n13 -> del k'th \n14 -> del value \n15 -> reverse");
		printf("\nEnter choice: ");
		scanf("%d",&s);
		switch(s)
		{
			case 2:
				display(head);
				break;
			case 3:
				getInput(&val, &k, &t_val, 1, 0, 0);
				head = insbeg(head, val);
				break;
			case 4:
				getInput(&val, &k, &t_val, 1, 0, 0);
				head = insend(head, val);
				break;
			case 5:
				getInput(&val, &k, &t_val, 1, 1, 0);
				head = insAfterK(head, k, val);
				break;
			case 6:
				getInput(&val, &k, &t_val, 1, 0, 1);
				head = insAfterNode(head, t_val, val);
				break;
			case 7:
				getInput(&val, &k, &t_val, 1, 1, 0);
				head = insBeforeK(head, k, val);
				break;
			case 8:
				getInput(&val, &k, &t_val, 1, 0, 1);
				head = insBeforeNode(head, t_val, val);
				break;
			case 9:
				head = delbeg(head);
				break;
			case 10:
				head = delend(head);
				break;
			case 11:
				getInput(&val, &k, &t_val, 0, 1, 0);
				head = delAfterK(head, k);
				break;
			case 12:
				getInput(&val, &k, &t_val, 0, 1, 0);
				head = delBeforeK(head, k);
				break;
			case 13:
				getInput(&val, &k, &t_val, 0, 1, 0);
				head = delKNode(head, k);
				break;
			case 14:
				getInput(&val, &k, &t_val, 0, 0, 1);
				head = delValue(head, t_val);
				break;
			case 15:
				head = reverse(head);
				break;
			default:
				printf("\nWrong choice !!!!");
		}
	}

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

void getInput(int* val, int* index, int* t_val, int f1, int f2, int f3)
{
	int v, i, target;
	if(f1) {
		printf("\nEnter new node data: ");
		scanf("%d", &v);
		*val = v;
	}
	if(f2) {
		printf("\nEnter K'th index: ");
		scanf("%d", &i);
		*index = i;
	}
	if(f3) {
		printf("\nEnter other node data: ");
		scanf("%d", &target);
		*t_val = target;
	}
}

node* reverse(node* head)
{
	node *curr = head, *t = NULL;
	while(curr != NULL) {
		t = curr->prev;
		curr->prev = curr->next;
		curr->next = t;
		curr = curr->prev;
	}
	if(t != NULL)
		head = t->prev;
	return head;
}