#include<stdio.h>
#include<stdlib.h>
#define NON -100

void create(int *a,int n,int i);
void preorder(int *a,int n,int i);
void inorder(int *a,int n,int i);
void postorder(int *a,int n,int i);

int main()
{
	int *arr = NULL;
	int choice,data,n,i;
	while(1) {
		printf("\n\n1 -> create\n2 -> preorder\n3 -> inorder\n4 -> postorder\n5 -> exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("Enter size of array = ");
			scanf("%d",&n);
			arr=(int *)malloc(sizeof(int)*n);
			for(i=0;i<n;i++)
				arr[i] = NON;
			create(arr,n,0);
			printf("Binary tree created\n");
			break;
		case 2:
			if(arr == NULL)
				printf("No tree created. First create a tree\n");
			else {
				printf("Preorder traversal :    ");
				preorder(arr,n,0);
				printf("\n");
			}
			break;
		case 3:
			if(arr == NULL)
				printf("No tree created. First create a tree\n");
			else {
				printf("Inorder traversal :    ");
				inorder(arr,n,0);
				printf("\n");
			}
			break;
		case 4:
			if(arr == NULL)
				printf("No tree created. First create a tree\n");
			else {
				printf("Postorder traversal :    ");
				postorder(arr,n,0);
				printf("\n");
			}
			break;
		case 5:
			return 0;
		default:
			printf("Enter valid option between 0 to 4\n");
			break;
		}
	};
	return 0;
}

void create(int *a,int n,int i) {
	int d;
	int ch;
	if(i < n) {
		printf("Enter data = ");
		scanf("%d",&d);
		a[i] = d;
		printf("\n1 -> add left child of %d",a[i]);
		printf("\n2 -> don't add\nEnter choice: ");
		scanf("%d",&ch);
		if(ch == 1)
			create(a,n,2*i+1);
		printf("\n1 -> add right child of %d",a[i]);
		printf("\n2 -> don't add\nEnter choice: ");
		scanf("%d",&ch);
		if(ch == 1)
			create(a,n,2*i+2);
	}
	else
		printf("Array full\n");
	return;
}

void preorder(int *a,int n,int i) {
	if(i >=n || a[i] == NON)
		return;
	printf("%d  ",a[i]);
	preorder(a,n,2*i+1);
	preorder(a,n,2*i+2);
	return;
}

void inorder(int *a,int n,int i) {
	if(i >=n || a[i] == NON)
		return;
	inorder(a,n,2*i+1);
	printf("%d  ",a[i]);
	inorder(a,n,2*i+2);
	return;
}

void postorder(int *a,int n,int i) {
	if(i >=n || a[i] == NON)
		return;
	postorder(a,n,2*i+1);
	postorder(a,n,2*i+2);
	printf("%d  ",a[i]);
	return;
}
