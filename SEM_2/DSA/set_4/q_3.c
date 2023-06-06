#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
	bool l;
	bool r;
}NODE;

NODE * create(NODE *p,int i);
void preorder(NODE *p);
void inorder(NODE *p);

int main()
{
	NODE *root;
	int choice,data;
	while(1) {
		printf("\n\n1 -> create\n2 -> preorder\n3 -> inorder\n4 -> exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			root=NULL;
			root=create(root,0);
			printf("Binary tree created successfully\n");
			break;
		case 2:
			if(root==NULL)
				printf("No tree created. First create a tree\n");
			else {
				printf("Preorder traversal :    ");
				preorder(root);
				printf("\n");
			}
			break;
		case 3:
			if(root==NULL)
				printf("No tree created. First create a tree\n");
			else {
				printf("Inorder traversal :    ");
				inorder(root);
				printf("\n");
			}
			break;
		case 4:
			return 0;
		default:
			break;
		}
	}
	return 0;
}

NODE * create(NODE *p,int i) {
	NODE *t,*c;
	int ch;
	if(p == NULL) {
		p=(NODE *)malloc(sizeof(NODE));
		p->data =- 999;
		p->l = false;
		p->r = false;
		p->right = p;
		p->left = p;
		p->left = create(p,0);
		return p;
	}
	else {
		t = (NODE *)malloc(sizeof(NODE));
		printf("Enter data = ");
		scanf("%d",&t->data);
		t->l = true;
		t->r = true;
		if(i == 0) {
			t->left = p->left;
			t->right = p;
		}
		else {
			t->left = p;
			t->right = p->right;
		}
		printf("\n1 -> add left child of %d", t->data);
		printf("\n2 -> don't add\nEnter choice: ");
		scanf("%d",&ch);
		if(ch == 1) {
			t->left = create(t,0);
			t->l = false;
		}
		printf("\n1 -> add left child of %d", t->data);
		printf("\n2 -> don't add\nEnter choice: ");
		scanf("%d",&ch);
		if(ch == 1) {
			t->right = create(t,1);
			t->r = false;
		}
	}
	return t;
}

void preorder(NODE *p) {
	NODE *t = p->left;
	while(t != p) {
		while(t->l == false) {
			printf("%d  ",t->data);
			t = t->left;
		}
		printf("%d  ",t->data);
		while(t->r == true) {
			t = t->right;
			if(t == p)
				break;
		}
		t = t->right;
	}
	return;
}

void inorder(NODE *p) {
	NODE *t = p->left;
	while(t != p) {
		while(t->l == false)
			t = t->left;
		printf("%d  ",t->data);
		while(t->r == true) {
			t = t->right;
			if(t == p)
				break;
			printf("%d  ",t->data);
		}
		t = t->right;
	}
	return;
}