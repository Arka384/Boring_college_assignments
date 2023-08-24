#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int coeff;
	int exp;
	struct node *next;
}node;

node* getnode(void);
node* create(node *);
void display(node *);
node* add_sub(node* , node* , int );    //0 = +, 1 = - ;
node* multiply(node* , node* );

int main()
{
    node* first_List = NULL;
    node* second_List = NULL;
    node* res = NULL;
    int choice;

    printf("\nCreating first polynomial:\n");
    first_List = create(first_List);
    display(first_List);

    printf("\nCreating second polynomial:\n");
    second_List = create(second_List);
    display(second_List);

    while(1) {
        printf("1 -> add polynomial_1 with polynomial_2\n");
        printf("2 -> subtract polynomial_1 with polynomial_2\n");
        printf("3 -> multiply polynomial_1 with polynomial_2\n");
        printf("4 -> Exit\n");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            res = add_sub(first_List, second_List, 0);
            display(res);
            break;
        case 2:
            res = add_sub(first_List, second_List, 1);
            display(res);
            break;
        case 3:
            res = multiply(first_List, second_List);
            display(res);
            break;
        case 4:
            return 0;
        default:
            printf("\nInvalid option given\n");
        }
    }

}

node* multiply(node* list_1, node* list_2)
{
    node* res = NULL;   //product of ploys
    node* resLast = NULL;
    node* currProd = NULL; 
    node* currProdLast = NULL;

    node* l1 = list_1;
    while(l1 != NULL) {
        currProd = NULL; 
        currProdLast = NULL;

        node* l2 = list_2;
        while(l2 != NULL) {
            node* t = getnode();
            t->coeff = l1->coeff * l2->coeff;
            t->exp = l1->exp + l2->exp;
            if(currProd == NULL) {
                currProd = t;
                currProdLast = currProd;
            }
            else {
                currProdLast->next = t;
                currProdLast = currProdLast->next;
            }
            l2 = l2->next;
        }
        res = add_sub(res, currProd, 0);
        l1 = l1->next;
    }

    return res;
}

node* add_sub(node* list_1, node* list_2, int mode)
{
    if(list_1 == NULL && list_2 == NULL)
        return NULL;
    if(list_1 == NULL)
        return list_2;
    if(list_2 == NULL)
        return list_1;


    node* res = NULL;   //added polynomial
    node* resLast = NULL;
    while((list_1 != NULL && list_2 != NULL) && (list_1->exp > list_2->exp)) {
        node* t = getnode();
        t->coeff = list_1->coeff;
        t->exp = list_1->exp;
        if(res == NULL)  {
            res = t;
            resLast = res;
        }
        else {
            resLast->next = t;
            resLast = resLast->next;
        }
        list_1 = list_1->next;
    }

    while((list_1 != NULL && list_2 != NULL) && (list_2->exp > list_1->exp)) {
        node* t = getnode();
        if(mode == 0)
            t->coeff = list_2->coeff;
        else if(mode == 1)
            t->coeff = -list_2->coeff;
        t->exp = list_2->exp;
        if(res == NULL)  {
            res = t;
            resLast = res;
        }
        else {
            resLast->next = t;
            resLast = resLast->next;
        }
        list_2 = list_2->next;
    }

    while(list_1 != NULL && list_2 != NULL) {
        node* t = getnode();
        if(mode == 0)
            t->coeff = list_1->coeff + list_2->coeff;
        else if(mode == 1)
            t->coeff = list_1->coeff - list_2->coeff;
        t->exp = list_1->exp;
        if(res == NULL)  {
            res = t;
            resLast = res;
        }
        else { 
            resLast->next = t;
            resLast = resLast->next;
        }
        list_1 = list_1->next;
        list_2 = list_2->next;
    }

    while(list_1 != NULL) {
        node* t = getnode();
        t->coeff = list_1->coeff;
        t->exp = list_1->exp;
        resLast->next = t;
        resLast = resLast->next;
        list_1 = list_1->next;
    }

    while(list_2 != NULL) {
        node* t = getnode();
        t->coeff = list_2->coeff;
        t->exp = list_2->exp;
        resLast->next = t;
        resLast = resLast->next;
        list_2 = list_2->next;
    }

    return res;
}

node *getnode()
{
	node *t;
	t=(node*)malloc(sizeof(node));
    t->coeff = 0;
    t->exp = 0;
	t->next=NULL;
	return t;
}

void display(node *head)
{
	node *t;
	if(head == NULL)
		printf("\npolynomial is empty");
	else
	{
		t = head;
		printf("\nThe polynomial list is-> ");
		while(t != NULL)
		{
            if(t->coeff == 0) {
                t = t->next;
                continue;
            }
			printf("%dx^%d",t->coeff, t->exp);
			t = t->next;
            if(t != NULL)
                printf(" + ");
		}
        printf("\n");
	}
}

node* create(node *head)
{   
    int highestDeg, x;
    printf("\nEnter the degree of the polynomial: ");
    scanf("%d", &highestDeg);

    while (highestDeg > -1) {
        printf("\nEnter coefficient for term with degree %d: ", highestDeg);
        node* t = getnode();
        scanf("%d", &x);
        // if(x == 0) {
        //     highestDeg--;
        //     continue;
        // }
        t->coeff = x;
        t->exp = highestDeg;
        if(head == NULL)
            head = t;
        else {
            node* temp = head;
            while(temp->next!=NULL)
                temp = temp->next;
            temp->next = t;
        }
        highestDeg--;
    }
	return head;
}