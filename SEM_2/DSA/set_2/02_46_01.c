#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *getnode(void);
void create(void);
void *insbeg(void);
void *insend(void);
void *insany(void);
void *delbeg(void);
void *delend(void);
void *delany(void);
void display(void);
void loader(void);
void sort(void);
void reverse(void);

node *head=NULL;

int main()
{
	int s;
	printf("\nPlease wait\nLoading contents...\n");
	loader();
	sleep(2);
	system("cls");
	printf("\nCreating linked list: \n");
	create();
	while(1)
	{
		printf("\n<1> to insbeg\n<2> to insend\n<3> to insany");
		printf("\n<4> to delbeg\n<5> to delend\n<6> to delany");
		printf("\n<7> to display\n<8> to sort list\n<9> to reverse list");
		printf("\n<10> to exit: ");
		scanf("%d",&s);
		switch(s)
		{
			case 1:
				insbeg();
				break;
			case 2:
				insend();
				break;
			case 3:
				insany();
				break;
			case 4:
				delbeg();
				break;
			case 5:
				delend();
				break;
			case 6:
				delany();
				break;
			case 7:
				display();
				break;
			case 8:
				sort();
				break;
			case 9:
				reverse();
				break;
			case 10:
				printf("\n!! Execution Terminated !!");
				return 0;
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

void create()
{
	head=getnode();
	printf("\nEnter first node information: ");
	scanf("%d",&head->data);
	head->next=NULL;
}

void *insbeg()
{
	node *t;
	if(head==NULL)
		create();
	else
	{
		t=getnode();
		printf("\nEnter new node information: ");
		scanf("%d",&t->data);
		t->next=head;
		head=t;	
	}
}

void *insend()
{
	node *t,*t1;
	if(head==NULL)
		create();
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
}

void *insany()
{
	node *t,*t1;
	if(head==NULL)
	{
		printf("\nList is empty");
		create();
	}
	else
	{
		t=head;
		int l;
		printf("\nEnter the value after which to insert: ");
		scanf("%d",&l);
		while(t->data!=l)
			t=t->next;
		t1=getnode();
		printf("\nEnter new node information: ");
		scanf("%d",&t1->data);
		t1->next=t->next;
		t->next=t1;	
	}
}

void display()
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

void *delbeg()
{
	node *t;
	t=head;
	head=head->next;
	printf("Deleted value %d",t->data);
	free(t);
}

void *delend()
{
	node *t,*t1;
	t=head;
	while(t->next->next!=NULL)
		t=t->next;
	t1=t->next;
	t->next=NULL;
	printf("Deleted value %d",t1->data);
	free(t1);
}

void *delany()
{
	node *t,*t1;
	int l,f=0;
	t=head;
	printf("\nEnter which value to delete: ");
	scanf("%d",&l);
	while(t->next != NULL)
	{
		if(t->next->data == l)
		{
			t1=t->next;
			t->next=t->next->next;
			printf("Deleted value %d",t1->data);
			free(t1);
			f=1;
			break;
		}
		t=t->next;
	}
	if(f==0)
		printf("\nGiven value not found");
}

void sort()
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
}

void reverse()
{
	node *pre=NULL,*curr,*t;
	curr=head;
	while(t!=NULL)
	{
		t=curr->next;
		curr->next=pre;
		pre=curr;
		curr=t;
	}
	head=pre;
}

void loader()
{
	int i;
	sleep(1);
	printf("\nPlease wait loading.....");
	for(i=0;i<90;i++)
	{
		usleep(1000);
		printf("%c",219);
	}
}
