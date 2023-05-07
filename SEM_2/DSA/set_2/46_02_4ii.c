#include<stdio.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node* next;
}node;

node* getnode(void);
node* create(node* , int );
void display(node* );
int listSize(node* );
node* delValue(node* , node* );
node* executePeople(node* , int , int , int );

int main()
{
    node* people = NULL;
    int start, skip, n;
    printf("\nEnter number of people: ");
    scanf("%d", &n);
    printf("\nEnter starting number: ");
    scanf("%d", &start);
    printf("\nEnter number of people to skip: ");
    scanf("%d", &skip);

    if(start > n || start < 1) {
        printf("\nInvalid start index given\n");
        return 0;
    }
    
    people = create(people, n);
    display(people);

    people = executePeople(people, n, start, skip);
    printf("\nThe luckey person was: %d\n", people->data);

    return 0;
}

node* executePeople(node* people, int n, int start, int skip)
{
    int count = 0;
    node* t = people;
    while(t->data != start)
        t = t->next;

    while (listSize(people) > 1)
    {
        for(int i=1;i<skip;i++)
            t = t->next;
        people = delValue(people, t);
        t = t->next;
        count++;
        printf("\nAfter %d iteration", count);
        display(people);
    }
    
    return people;
}

node *getnode()
{
	node *t;
	t = (node*)malloc(sizeof(node));
	t->next = NULL;
	return t;
}

node* create(node *head, int n)
{
    node* last = NULL;
    int i = 1;
    while(i <= n) {
        node* t = getnode();
        t->data = i;
        if(head == NULL) {
            head = t;
            t->next = head;
            last = head;
        }
        else {
            t->next = head;
            last->next = t;
            last = last->next;
        }
        i++;
    }
    return head;
}

int listSize(node* head)
{
    int size = 0;
    if(head == NULL)
        return size;
    node* t = head;
    while(t->next != head) {
        size++;
        t = t->next;
    }
    return size + 1;
}

node* delValue(node* head, node* ptr)
{
    //deleting the next node of ptr
    if(ptr->next == head) {
        head = head->next;
        ptr->next = head;
        return head;
    }
    node* t = ptr->next;
    ptr->next = t->next;
    free(t);
    return head;
}

void display(node *head)
{
	node *t;
	if(head == NULL)
		printf("\nList is empty");
	else
	{
		t = head;
		printf("\nPeople left-> ");
		while(t->next != head)
		{
			printf("%d ", t->data);
			t = t->next;
		}
        printf("%d ", t->data);
	}
}