#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int data;
    struct node *next;
}node;
node *head = NULL;

node *getNode(void);
void create(void);
void insertEnd(void);
void delByValue(void);
void delByIndex(void);
void display(void);
void searchList(void);

int main()
{
    int s;
    printf("\nCreating linked list: \n");
    create();
    while(1) {
        printf("\n<1> to insert new node");
		printf("\n<2> to delele node by value");
		printf("\n<3> to delele node by index");
		printf("\n<4> to display the list");
		printf("\n<5> to search the list");
		printf("\n<6> to exit");
		printf("\nEnter your choice: ");
		scanf("%d",&s);

        switch (s)
        {
        case 1:
            insertEnd();
            break;
        case 2:
            delByValue();
            break;
        case 3:
            delByIndex();
            break;
        case 4:
            display();
            break;
        case 5:
            searchList();
            break;
        case 6:
            return 0;
        default:
            break;
        }
    }
    
    
}

node *getNode() {
    node *t;
    t = (node*)malloc(sizeof(node));
    t->next = NULL;
    return t;
}

void create() {
    head = getNode();
    printf("\nEnter first node data: ");
    scanf("%d", &head->data);
}

void insertEnd() {
    if(head == NULL) {
        create();
        return;
    }
    node *t = head;
    while(t->next != NULL)
        t = t->next;
    node *temp = getNode();
    printf("\nEnter new node data: ");
    scanf("%d", &temp->data);
    t->next = temp;
}

void delByValue() {
    if(head == NULL) {
        printf("\nList is empty");
        return;
    }
    node *t = head, *t1;
    int val = 0;
    printf("\nEnter the value to delete: ");
    scanf("%d", &val);

    if(head->data == val) {
        printf("\nThe value deleted is: %d", t->data);
        head = head->next;
        free(t);
        return;
    }

    while (t->next != NULL && t->next->data != val)
        t = t->next;
    if(t->next == NULL) {
        printf("\nValue not found");
        return;
    }
    
    t1 = t->next;
    t->next = t->next->next;
    printf("\nThe value deleted is: %d", t1->data);
    free(t1);
}

void delByIndex() {
    if(head == NULL) {
        printf("\nList is empty");
        return;
    }
    node *t = head, *t1;
    int index, i = 0;
    printf("\nEnter the index to delete: ");
    scanf("%d", &index);

    if(index == 0) {
        printf("\nThe value deleted is: %d", t->data);
        head = head->next;
        free(t);
        return;
    }

    while (i++ < index-1 && t->next != NULL)
        t = t->next;
    if(t->next == NULL) {
        printf("\nInvalid index given");
        return;
    }

    t1 = t->next;
    t->next = t->next->next;
    printf("\nThe value deleted is: %d", t1->data);
    free(t1);
}

void searchList() {
    node *t = head;
    int val, i = 0;
    printf("\nEnter value to search: ");
    scanf("%d", &val);
    while(t != NULL) {
        if(t->data == val) {
            printf("\n%d is found at index %d", val, i);
            return;
        }
        t = t->next;
        i++;
    }
    printf("\nGiven value %d is not present in the list", val);
}

void display() {
    node *t = head;
    printf("\nThe list contents are: ");
    while(t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL");
}