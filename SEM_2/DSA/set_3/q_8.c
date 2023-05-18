#include<stdio.h>
#include <string.h>
#include<malloc.h>

typedef struct node{
	char data;
	struct node *next;
}node;
node* stackTop = NULL;

node* getnode(void);
char peek(void);
void push(char );
void pop(void);
int isEmpty(void);

int main()
{
    /*
        some expressions for checking
        ([{}()]{}())
        ([{}()]{}())
        [{}()[({})][]()]
        {}([][()])()
    */
    char expression[30] = {" "};
    printf("\nEnter expression of brackets\n: ");
    fgets(expression, 30, stdin);

    int f = 0;
    for(int i=0; i<strlen(expression); i++) {
        char symb = expression[i];
        if(symb == '(' || symb == '{' || symb == '[')
            push(symb);

        else if (symb == ')' && isEmpty() == 0) {
            if(peek() == '(') pop();
            else { f = 1; break; }
        }
        else if (symb == '}' && isEmpty() == 0) {
            if(peek() == '{') pop();
            else { f = 1; break; }
        }
        else if (symb == ']' && isEmpty() == 0) {
            if(peek() == '[') pop();
            else { f = 1; break; }
        }
    }

    if(isEmpty() != 1)
        f = 1;

    if(f == 1) printf("\nRxpression is NOT balanced");
    else printf("\nExpression is balanced\n");
    return 0;
}

char peek() {
    return stackTop->data;
}

void push(char val) {
	node* t;
	t = getnode();
	t->data = val;
	t->next = stackTop;
	stackTop = t;
}

void pop() {
	if(stackTop == NULL)
		return;
	node *t = stackTop;
	stackTop = stackTop->next;
	free(t);
}

int isEmpty(void)	{
	if(stackTop == NULL) return 1;
    else return 0;
}

node *getnode() {
	node *t;
	t = (node*)malloc(sizeof(node));
	t->next = NULL;
	return t;
}