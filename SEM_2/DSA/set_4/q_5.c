#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}NODE;

NODE* create(int n);
int hight(NODE *p);
int getbalancefactor(NODE *p);
NODE* rotateleft(NODE *p);
NODE* rotateright(NODE *p);
NODE* insertrecursive(NODE *p,int n);
void preorder(NODE *p);
void inorder(NODE *p);
void postorder(NODE *p);
NODE* searchiterative(NODE *p,int n);
NODE* small(NODE *p);
NODE* deletenode(NODE *p,int n);


int main()
{
	NODE *root = NULL;
	int choice,n;
	while(1) {
		printf("\n\n1 -> Insert recursive\n2 -> Preorder\n3 -> Inorder\n4 -> Postorder\n");
		printf("5 -> Search\n6 -> Find height\n7 -> Delete\n8 -> exit");
		printf("\nEnter your choice :\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("Enter the data to be inserted = ");
			scanf("%d",&n);
			root = insertrecursive(root,n);
			break;
		case 2:
			preorder(root);
			break;
		case 3:
			inorder(root);
			break;
		case 4:
			postorder(root);
			break;
		case 5:
			printf("Enter the data to be search = ");
			scanf("%d",&n);
			if(searchiterative(root,n))
				printf("Value found\n");
			else
				printf("Value not found");
			break;
		case 6:
			if(hight(root) == -1)
				printf("Tree is empty\n");
			else
				printf("Tree hight is = %d\n", hight(root));
			break;
		case 7:
			printf("Enter the data to be deleted = ");
			scanf("%d",&n);
			root = deletenode(root,n);
			break;
		case 8:
			return 0;
		default:
			break;
		}
	}
	return(0);
}

NODE* create(int n) {
	NODE *t = (NODE *)malloc(sizeof(NODE));
	t->data = n;
	t->left = NULL;
	t->right = NULL;
	return(t);
}

int hight(NODE *p) {
	int lh,rh;
	if(p == NULL)
		return 0;
	lh = hight(p->left);
	rh = hight(p->right);
	if(lh > rh)
		return(lh + 1);
	else
		return(rh + 1);	
}

int getbalancefactor(NODE *p) {
	if(p == NULL)
		return(-1);
	return(hight(p->left) - hight(p->right));
}

NODE* rotateleft(NODE *p) {
	NODE *q = p->right, *t = q->left;
	q->left = p;
	p->right = t;
	return(q);
}

NODE* rotateright(NODE *p) {
	NODE *q = p->left, *t = q->right;
	q->right = p;
	p->left = t;
	return(q);
}

NODE* insertrecursive(NODE *p,int n) {
	int b;	
	if(p == NULL)
		return(create(n));
	if(p->data == n) {
		printf("No dublicate data please\n");
		return(p);
	}
	else if(p->data < n)
		p->right = insertrecursive(p->right, n);
	else
		p->left = insertrecursive(p->left, n);
	b = getbalancefactor(p);
	//left left
	if((b > 1) && ((p->left->data) > n)) {
		printf("Right Rotation\n");
		return(rotateright(p));
	}
	//right right
	if((b <- 1) && ((p->right->data) < n)) {
		printf("Left rotation\n");
		return(rotateleft(p));
	}
	//left right
	if((b > 1) && (p->left->data < n)) {
		printf("Left rotation\n");
		p->left = rotateleft(p->left);
		printf("Right Rotation\n");
		return(rotateright(p));
	}
	//right left
	if((b < -1) && (p->right->data > n)) {
		printf("Right Rotation\n");
		p->right = rotateright(p->right);
		printf("Left rotation\n");
		return(rotateleft(p));
	}
	return(p);
}

void preorder(NODE *p) {
	if(p == NULL)
		return;
	printf("%d ",p->data);
	preorder(p->left);
	preorder(p->right);
	return;
}

void inorder(NODE *p) {
	if(p == NULL)
		return;
	inorder(p->left);
	printf("%d ",p->data);
	inorder(p->right);
	return;
}

void postorder(NODE *p) {
	if(p == NULL)
		return;
	postorder(p->left);
	postorder(p->right);
	printf("%d ",p->data);
	return;
}

NODE* searchiterative(NODE *p,int n) {
	NODE *t = p;
	if(p == NULL)
		return(NULL);
	while(t != NULL) {
		if(t->data == n)
			return(t);
		if(t->data < n)
			t = t->right;
		else
			t = t->left;
	}
	return(NULL);
}

NODE* small(NODE *p) {
	NODE *c = p;
	while(c->left != NULL)
		c = c->left;
	return(c);
}

NODE* deletenode(NODE *p,int n) {
	NODE *t;
	int b;
	if(p == NULL)
		return(p);
	if(p->data < n)
		p->right = deletenode(p->right, n);
	else if(p->data > n)
		p->left = deletenode(p->left, n);
	else {
		if(p->left == NULL) {
			t = p->right;
			free(p);
			return(t);	
		}
		if(p->right == NULL) {
			t = p->left;
			free(p);
			return(t);
		}
		t = small(p->right);
		p->data = t->data;
		p->right = deletenode(p->right, t->data);	
	}
	b = getbalancefactor(p);
	//left left
	if(b == 2 && getbalancefactor(p->left) >= 0) {
		printf("Right Rotation\n");
		return(rotateright(p));
	}
	//right right
	if(b == -2 && getbalancefactor(p->right) <= 0) {
		printf("Left Rotation\n");
		return(rotateleft(p));
	}
	//left right
	if (b == 2 && getbalancefactor(p->left) == -1) {
		printf("Left Rotation\n");
		p->left = rotateleft(p->left);
		printf("Right Rotation\n");
		return(rotateright(p));
	}
	//right left
	if (b == -2 && getbalancefactor(p->right) == 1) {
		printf("Right Rotation\n");
		p->right = rotateright(p->right);
		printf("Left Rotation\n");
		return(rotateleft(p));
	}
	return(p);
}