#include<stdio.h>
#include <string.h>
#include<malloc.h>

typedef struct node{
	char data;
	struct node *next;
}node;
node* stackTop = NULL;

node* getnode(void);
// void traverse(void);
void push(char );
char pop(void);
int isEmpty(void);
int priority(char );

int main()
{
	char infix[20] = {"a+b*c+d"};
	// char infix[20] = {"((a+b)-c*(d/e))+f"};
	// char infix[20] = {"x^y/(5*z)+2"};
	
	char postfix[20] = {" "}, t;
	int x = 0;

	for(int i=0; i<strlen(infix); i++) {
		char symbol = infix[i];
		switch(symbol) {
            case '(':
                push(symbol);
                break;
            case ')':
                while((t = pop()) != '(')
					postfix[x++] = t;
                break;
			case '+':
            case '-':
            case '*':
            case '/':
            case '^':
				while(isEmpty() != 1 && priority(symbol) <= priority(stackTop->data))
					postfix[x++] = pop();
				push(symbol);
				break;
            default:
				postfix[x++] = symbol;
                break;
		}
	}
	
	while(isEmpty() != 1)
        postfix[x++] = pop();
	postfix[x] = '\0';
	for(int i = 0; i <x; i++)
        printf("%c ", postfix[i]);

	printf("\n");
}

int priority(char symbol) {
	switch(symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
		default:
            return 0;
    }
} 

void push(char val)
{
	node* t;
	t = getnode();
	t->data = val;
	t->next = stackTop;
	stackTop = t;
}

char pop()
{
	char c = '#';
	if(stackTop == NULL) {
		printf("\nStack Underflow\n");
		return c;
	}
	node *t = stackTop;
	c = stackTop->data;
	stackTop = stackTop->next;
	free(t);
	return c;
}

int isEmpty(void)	{
	if(stackTop == NULL) return 1;
    else return 0;
}

node *getnode()
{
	node *t;
	t = (node*)malloc(sizeof(node));
	t->next = NULL;
	return t;
}

// void traverse()
// {
// 	node *t;
// 	if(stackTop == NULL)
// 		printf("\nList is empty\n");
// 	else {
// 		t = stackTop;
// 		printf("\nThe stack is-> ");
// 		while(t != NULL) {
// 			printf("%c ",t->data);
// 			t = t->next;
// 		}
// 	}
// }
