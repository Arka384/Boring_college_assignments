#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node* getnode(void);
node* create(node *);
void display(node *);

node* insbeg(node *);
node* insend(node *);
node* insAfterK(node *);
node* insAfterNode(node *);
node* insBeforeK(node *);
node* insBeforeNode(node *);

node* delbeg(node *);
node* delend(node *);
node* delAfterK(node *);
node* delBeforeK(node *);
node* delKNode(node *);
node* delValue(node *);

node* reverse(node *);
node* sort(node *);
void search(node* , int );
node* merge(node* );
node* mergeHelper(node* , node** , int );
node* concat(node* );
int isEqual(node* , node* );


int main()
{
	node* head=NULL;
	node* list = NULL;

	int s, tempVal;
	printf("\nCreating linked list: \n");
	head = create(head);

	/*
		2 -> display, 3 -> ins front, 4 -> ins end
		5 -> ins after k'th, 6 -> ins after node,
		7 -> ins before k'th, 8 -> ins before node,

		9 -> del first, 10 -> del last
		11 -> del after k'th, 12 -> del before k'th
		13 -> del k'th, 14 -> del value

		15 -> reverse, 16 -> sort, 17 -> search
		18-> merge in ascending, 19 -> concatenate, 20 -> equality

	*/

	while(1)
	{
		printf("\nEnter choice: ");
		scanf("%d",&s);
		switch(s)
		{
			case 2:
				display(head);
				break;
			case 3:
				head = insbeg(head);
				break;
			case 4:
				head = insend(head);
				break;
			case 5:
				head = insAfterK(head);
				break;
			case 6:
				head = insAfterNode(head);
				break;
			case 7:
				head = insBeforeK(head);
				break;
			case 8:
				head = insBeforeNode(head);
				break;
			case 9:
				head = delbeg(head);
				break;
			case 10:
				head = delend(head);
				break;
			case 11:
				head = delAfterK(head);
				break;
			case 12:
				head = delBeforeK(head);
				break;
			case 13:
				head = delKNode(head);
				break;
			case 14:
				head = delValue(head);
				break;
			case 15:
				head = reverse(head);
				display(head);
				break;
			case 16:
				head = sort(head);
				display(head);
				break;
			case 17:
				printf("\nEnter data to search: ");
				scanf("%d", &tempVal);
				search(head, tempVal);
				break;
			case 18:
				list = merge(head);
				display(list);
				break;
			case 19:
				list = concat(head);
				display(list);
				break;
			case 20:
				int x = isEqual(head, list);
				(x == 1) ? printf("\nEQUAL") : printf("\nNOT EQUAL");
				break;
			default:
				printf("\nWrong choice !!!!");
		}
	}
}

node *getnode()
{
	node *t;
	t=(node*)malloc(sizeof(node));
	t->next=NULL;
	return t;
}

//I
node* create(node *head)
{
	head=getnode();
	printf("\nEnter first node information: ");
	scanf("%d",&head->data);
	head->next=NULL;
	return head;
}

//II
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

//III
node* insbeg(node *head)
{
	node *t;
	if(head==NULL)
		head = create(head);
	else
	{
		t=getnode();
		printf("\nEnter new node information: ");
		scanf("%d",&t->data);
		t->next=head;
		head=t;	
	}
	return head;
}

//IV
node* insend(node *head)
{
	node *t,*t1;
	if(head==NULL)
		head = create(head);
	else
	{
		t1=getnode();
		printf("\nEnter new node information: ");
		scanf("%d",&t1->data);
		t=head;
		while(t->next!=NULL)
			t=t->next;
		t->next=t1;
	}
	return head;
}

//V
node* insAfterK(node *head)
{
	node *t,*t1;
	if(head==NULL) {
		printf("\nList is empty");
		head = create(head);
	}
	else {
		int k;
		printf("\nEnter K'th index: ");
		scanf("%d",&k);
		if(k < 0) { 
			printf("\nInvalid location given");
			return head;
		}
		if(k == 0) {
			head = insbeg(head);
			return head;
		}

		t=head;
		for(int i=1;i<k;i++) {
			if(t->next != NULL)
				t = t->next;
			else {
				printf("\nInvalid location given");
				return head;
			}
		}
		//now insert after t
		t1=getnode();
		printf("\nEnter new node information: ");
		scanf("%d",&t1->data);
		t1->next=t->next;
		t->next=t1;	
	}
	return head;
}

//VI
node* insAfterNode(node *head)
{
	node *t,*t1;
	if(head==NULL) {
		printf("\nList is empty");
		head = create(head);
		return head;
	}

	int val;
	printf("\nEnter node value after which to insert: ");
	scanf("%d",&val);
	
	t=head;
	while(t->data!=val) {
		if(t->next != NULL)
			t=t->next;
		else {
			printf("\nValue not present");
			return head;
		}
	}

	//now insert after t
	t1=getnode();
	printf("\nEnter new node information: ");
	scanf("%d",&t1->data);
	t1->next=t->next;
	t->next=t1;	

	return head;
}

//VII
node* insBeforeK(node *head)
{
	node *t,*t1;
	if(head==NULL) {
		printf("\nList is empty");
		head = create(head);
		return head;
	}

	int k;
	printf("\nEnter K'th index: ");
	scanf("%d",&k);
	if(k <= 0) { 
		printf("\nInvalid location given");
		return head;
	}
	if(k == 1) {
		head = insbeg(head);
		return head;
	}

	t=head;
	for(int i=1;i<k-1;i++) {
		if(t->next != NULL)
			t = t->next;
		else {
			printf("\nInvalid location given");
			return head;
		}
	}
	//now insert after t
	t1=getnode();
	printf("\nEnter new node information: ");
	scanf("%d",&t1->data);
	t1->next=t->next;
	t->next=t1;

	return head;
}

//VIII
node* insBeforeNode(node *head)
{
	node *t,*t1;
	if(head==NULL) {
		printf("\nList is empty");
		head = create(head);
		return head;
	}

	int val;
	printf("\nEnter node value before which to insert: ");
	scanf("%d",&val);
	
	t=head;
	if(t->data == val) {
		head = insbeg(head);
		return head;
	}

	while(t->next != NULL && t->next->data != val) {
		t = t->next;
	}
	if(t->next == NULL) {
		printf("\nValue not present");
		return head;
	}
	//now insert after t
	t1=getnode();
	printf("\nEnter new node information: ");
	scanf("%d",&t1->data);
	t1->next=t->next;
	t->next=t1;

	return head;
}

//IX
node* delbeg(node *head)
{
	if(head == NULL) {
		printf("\nList is empty");
		return head;
	}
	node *t;
	t=head;
	head=head->next;
	printf("Deleted value %d",t->data);
	free(t);

	return head;
}

//X
node* delend(node *head)
{
	//add check if only one element present
	if(head == NULL) {
		printf("\nList is empty");
		return head;
	}
	if(head->next == NULL) {
		head = delbeg(head);
		return head;
	}

	node *t,*t1;
	t=head;
	while(t->next->next!=NULL)
		t=t->next;
	t1=t->next;
	t->next=NULL;
	printf("Deleted value %d",t1->data);
	free(t1);

	return head;
}

//XI
node* delAfterK(node *head)
{
	if(head == NULL) {
		printf("\nList is empty");
		return head;
	}

	node *t, *t1;
	int k;
	printf("\nEnter K'th index: ");
	scanf("%d",&k);
	if(k < 0) { 
		printf("\nInvalid location given");
		return head;
	}
	if(k == 0) {
		head = delbeg(head);
		return head;
	}

	t = head;
	for(int i=1;i<k;i++) {
		if(t->next != NULL)
			t = t->next;
		else {
			printf("\nInvalid location given");
			return head;
		}
	}

	if(t->next == NULL) {
		printf("\nInvalid location given");
		return head;
	}

	//now delete after k
	t1 = t->next;
	t->next = t->next->next;
	printf("Deleted value %d",t1->data);
	free(t1);

	return head;
}

//XII
node* delBeforeK(node *head)
{
	if(head == NULL) {
		printf("\nList is empty");
		return head;
	}

	node *t, *t1;
	int k;
	printf("\nEnter K'th index: ");
	scanf("%d",&k);
	if(k <= 1) { 
		printf("\nInvalid location given");
		return head;
	}
	if(k == 2) {
		if(head->next != NULL) {
			head = delbeg(head);
			return head;
		}
		else {
			printf("\nInvalid location given");
			return head;
		}
	}
	if(head->next == NULL) {
		printf("\nInvalid location given");
		return head;
	}


	t = head;
	for(int i=1;i<k-2;i++) {
		if(t->next != NULL)
			t = t->next;
		else {
			printf("\nInvalid location given");
			return head;
		}
	}
	printf("%d", t->data);
	if(t->next->next == NULL) {
		printf("\nInvalid location given");
		return head;
	}

	//now delete after k
	t1 = t->next;
	t->next = t->next->next;
	printf("Deleted value %d",t1->data);
	free(t1);

	return head;
}

//XIII
node* delKNode(node *head)
{
	if(head == NULL) {
		printf("\nList is empty");
		return head;
	}

	node *t, *t1;
	int k;
	printf("\nEnter K'th index: ");
	scanf("%d",&k);
	if(k < 1) {
		printf("\nInvalid location given");
		return head;
	}
	if(k == 1) {
		head = delbeg(head);
		return head;
	}

	t = head;
	for(int i=1;i<k-1;i++) {
		if(t->next != NULL)
			t = t->next;
		else {
			printf("\nInvalid location given");
			return head;
		}
	}
	if(t->next == NULL) {
		printf("\nInvalid location given");
		return head;
	}

	//now delete after k
	t1 = t->next;
	t->next = t->next->next;
	printf("Deleted value %d",t1->data);
	free(t1);
	
	return head;
}

//XIV
node* delValue(node *head)
{
	if(head == NULL) {
		printf("\nList is empty");
		return head;
	}

	node *t,*t1;
	int val;
	t=head;
	printf("\nEnter which value to delete: ");
	scanf("%d",&val);
	if(head->data == val) {
		head = delbeg(head);
		return head;
	}

	while(t->next != NULL && t->next->data != val) {
			t = t->next;
	}
	printf("%d", t->data);
	if(t->next == NULL) {
		printf("\nValue not present");
		return head;
	}

	t1 = t->next;
	t->next = t->next->next;
	printf("Deleted value %d",t1->data);
	free(t1);

	return head;
}

//XV
node* reverse(node *head)
{
	node *pre=NULL,*curr,*t;
	curr=head;
	while(curr!=NULL)
	{
		t=curr->next;
		curr->next=pre;
		pre=curr;
		curr=t;
	}
	head=pre;

	return head;
}

//XVI
node* sort(node *head)
{
	node *t,*tlast=NULL;
	int swapped,t1;
	do
	{
		swapped=0;
		t=head;
		while(t->next!=tlast)
		{
			if(t->data > t->next->data)
			{
				t1=t->data;
				t->data=t->next->data;
				t->next->data=t1;
				swapped=1;
			}
			t=t->next;
		}
		tlast=t;
	}while(swapped);

	return head;
}

//XVII
void search(node* head, int val)
{
	node *t;
	if(head==NULL) {
		printf("\nList is empty");
		return;
	}

	t=head;
	while(t!=NULL) {
		if(t->data == val) {
			printf("\nGiven value is present");
			return;
		}
		t=t->next;
	}
	
	printf("\nGiven value is NOT present in the list");
}

//XVIII
node* merge(node* head)
{
	node* otherHead = NULL;
	int n;
	printf("\nEnter data for second list: ");
	otherHead = create(otherHead);
	printf("\nEnter number of data to insert: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		otherHead = insend(otherHead);

	printf("\nThe first list after sorting is:");
	head = sort(head);
	display(head);
	printf("\nThe other list after sorting is:");
	otherHead = sort(otherHead);
	display(otherHead);

	node* t1 = head;
	node* t2 = otherHead;
	node* merged = NULL;
	node* curr = NULL;

	while(t1 != NULL && t2 != NULL) {
		if(t1->data < t2->data) {
			merged = mergeHelper(merged, &curr, t1->data);
			t1 = t1->next;
		}
		else {
			merged = mergeHelper(merged, &curr, t2->data);
			t2 = t2->next;
		}
	}

	while(t1 != NULL) {
		merged = mergeHelper(merged, &curr, t1->data);
		t1 = t1->next;
	}
	while(t2 != NULL) {
		merged = mergeHelper(merged, &curr, t2->data);
		t2 = t2->next;
	}

	return merged;
}

node* mergeHelper(node* tempHead, node** curr, int val)
{
	if(tempHead == NULL) {
		tempHead = getnode();
		tempHead->data = val;
		(*curr) = tempHead;
	}
	else {
		node* temp = getnode();
		temp->data = val;
		(*curr)->next = temp;
		(*curr) = (*curr)->next;
	}
	return tempHead;
}

//XIX
node* concat(node* head)
{
	node* otherHead = NULL;
	int n;
	printf("\nEnter data for second list: ");
	otherHead = create(otherHead);
	printf("\nEnter number of data to insert: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		otherHead = insend(otherHead);

	node* merged = NULL;
	node* curr = NULL;
	node* t = head;
	while(t != NULL) {
		merged = mergeHelper(merged, &curr, t->data);
		t = t->next;
	}
	t = otherHead;
	while(t != NULL) {
		merged = mergeHelper(merged, &curr, t->data);
		t = t->next;
	}

	return merged;
}

//XX
int isEqual(node* first, node* second)
{
	node* t1 = first;
	node* t2 = second;

	while(t1 != NULL && t2 != NULL) {
		if(t1->data != t2->data)
			return 0;
		t1 = t1->next;
		t2 = t2->next;
	}
	if(t1 == NULL && t2 == NULL)
		return 1;
	else
		return 0;
}