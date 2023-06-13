#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;
node* stackTop = NULL;

node* getnode(void);
void traverse(void);
void push(int );
int pop(void);
int isEmpty(void);
int isOperator(char );
int getNextData(char* ,int* );

int main() {
    // char postfix[20] = {"2 3 1 * + 9 -"};
    // char postfix[30] = {"10 22 + 8 / 6 * 5 +"};
    // char postfix[30] = {"100 2 * 40 + 26 * 2 / - 22 +"};
    // char postfix[30] = {"5 9 3 / 2 1 + * + 6 2 / - 3 +"};
    // char postfix[30] = {"4 3 2 ^ + 1 8 * 2 2 + / - 2 -"};
    // char postfix[35] = {"2 3 ^ 1 - 4 2 / 6 * + 3 1 + 2 / -"};
    char postfix[50] = {" "};
    printf("\nEnter postfix expression\n: ");
    fgets(postfix, 50, stdin);

    int i = 0;
    
    while(i < strlen(postfix)) {
        char symbol = postfix[i];
        if(isOperator(symbol)) {
            int m = pop();
            int n = pop();
            switch (symbol)
            {
            case '+':
                push(n + m);
                break;
            case '-':
                push(n - m);
                break;
            case '*':
                push(n * m);
                break;
            case '/':
                push(n / m);
                break;
            case '^':
                push(pow(n , m));
                break;
            default:
                break;
            }
            i += 2;
        }
        else {
            int data = getNextData(postfix, &i);
            //printf("\n dd = %d", data);
            push(data);
        }
    }

    printf("\nEvaluated Value = %d\n", stackTop->data);

}

int getNextData(char* postfix, int* index) {
    char word[10] = {" "};
    int i = 0;
    while(postfix[*index] != '\0') {
        if(postfix[*index] == ' ') {
            *index = *index + 1;
            break;
        }
        word[i++] = postfix[*index];
        *index = *index + 1;
    }
    word[i] = '\0';
    return atoi(word);
}

int isOperator(char c) {
    if(c == 43 || c == 42 || c == 45 || c == 47 || c == 94) return 1;
    else return 0;
}

node* getnode() {
    node* temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    return temp;
}

int isEmpty() {
    if(stackTop == NULL) return 1;
    else return 0;
}

void push(int val) {
	node* t;
	t = getnode();
	t->data = val;
	t->next = stackTop;
	stackTop = t;
}

int pop() {
    char c = '#';
    if(stackTop == NULL) {
		printf("\nStack Underflow\n");
        return c;
    }
    node* t = stackTop;
    c = t->data;
    stackTop = stackTop->next;
    free(t);
    return c;
}


void traverse()
{
	node *t;
	if(stackTop == NULL)
		printf("\nList is empty\n");
	else {
		t = stackTop;
		printf("\nThe stack is-> ");
		while(t != NULL) {
			printf("%c ",t->data);
			t = t->next;
		}
	}
}