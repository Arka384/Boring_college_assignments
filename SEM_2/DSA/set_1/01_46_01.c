#include <stdio.h>
#include <malloc.h>

int* create(int );
void display(int*, int);
void count(int );
void reverse(int* ,int);
void getIndex(int* ,int, int);
void getElement(int* ,int , int);
int* insert(int* ,int* , int , int);
int* delete(int*, int*, int );
int* merge(int*, int*);
void split(int*, int, int);
void sort(int*, int);
void search(int*, int, int);

int main()
{

	//sizeof(arr)/sizeof(arr[0])

	int* arr;
	int* splitArr;
	int n, choice, temp, index;
	
	printf("\nCreating array\n");
	printf("\nEnter number of elements: ");
	scanf("%d", &n);
	arr = create(n);
	
	while(1)
	{
		printf("\n1->Display");
		printf("\n2->Count");
		printf("\n3->Reverse");
		printf("\n4->Find index of element");
		printf("\n5->Get element at index");
		printf("\n6->Insert");
		printf("\n7->Delete");
		printf("\n8->Merge");
		printf("\n9->Split");
		printf("\n10->Sort");
		printf("\n11->Search");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				display(arr, n);
				break;
			case 2:
				count(n);
				break;
			case 3:
				reverse(arr, n);
				display(arr, n);
				break;
			case 4:
				printf("\nEnter element to find index: ");
				scanf("%d", &temp);
				getIndex(arr, n, temp);
				break;
			case 5:
				printf("\nEnter index to find element: ");
				scanf("%d", &temp);
				getElement(arr, n, temp);
				break;
			case 6:
				printf("\nEnter index to insert: ");
				scanf("%d", &index);
				printf("\nEnter element to insert at that index: ");
				scanf("%d", &temp);
				arr = insert(arr, &n, index, temp);
				display(arr, n);
				break;
			case 7:
				printf("\nEnter index to delete: ");
				scanf("%d", &index);
				arr = delete(arr, &n, index);
				display(arr, n);
				break;
			case 8:
				arr = merge(arr, &n);
				display(arr, n);
				break;
			case 9:
				printf("\nEnter index to split: ");
				scanf("%d", &index);
				split(arr, n, index);
				break;
			case 10:
				sort(arr, n);
				display(arr, n);
				break;
			case 11:
				printf("\nEnter element to insert at that index: ");
				scanf("%d", &temp);
				search(arr, n, temp);
				break;
				
			default:
				printf("\nInvalid choice");
		}
		
	}
	
}

void search(int* arr, int n, int elem) {
	for(int i=0;i<n;i++) {
		if(arr[i] == elem) {
			printf("\nElement found at index %d\n", i);
			return;
		}
	}
	printf("\nElement not found\n");
}

void sort(int* arr, int n) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n-i-1;j++) {
			if(arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int* delete(int* arr, int* n, int k) {
	int* a = (int*)malloc(sizeof(int)*(*n-1));
	int i,j=0;
	for(i=0;i<k;i++)
		a[j++] = arr[i];
	for(i=k+1;i<*n;i++)
		a[j++] = arr[i];

	*n = *n - 1;
	return a;
}

int* insert(int* arr, int* n, int k, int element) {
	int* a = (int*)malloc(sizeof(int)*(*n+1));
	int i;
	for(i=0;i<k;i++)
		a[i] = arr[i];
	
	a[i++] = element;
	for(int j=k;j<*n;j++,i++)
		a[i] = arr[j];
	free(arr);
	*n = *n + 1;
	return a;
}

void split(int* arr, int n, int k) {
	int rightArrSize = n - k;
	int leftArrSize = n - rightArrSize;
	int *leftArr = (int*)malloc(sizeof(int)*leftArrSize);
	int *rightArr = (int*)malloc(sizeof(int)*rightArrSize);
	
	for(int j=0,i=0;i<k;i++,j++)
		leftArr[j] = arr[i];
	for(int j=0,i=k;i<n;i++,j++)
		rightArr[j] = arr[i];
	
	display(leftArr, leftArrSize);
	display(rightArr, rightArrSize);
}

int* merge(int* arr, int* n) {
	int newSize;
	printf("\nCreate a new Array\n");
	printf("\nEnter size of new array: ");
	scanf("%d", &newSize);
	int* tempArr = create(newSize);
	
	printf("\nMerging arrays");
	int* mergedArr = (int*)malloc(sizeof(int)*(*n+newSize));
	
	int i;
	for(i=0;i<*n;i++)
		mergedArr[i] = arr[i];
	for(int j=0;j<newSize;j++,i++)
		mergedArr[i] = tempArr[j];
	
	*n = *n + newSize;
	return mergedArr;
}

void getElement(int* arr, int n, int k) {
	if(k >= n || k < 0) {
		printf("\nInvalid input");
		return;
	}
	
	printf("\nElement at %d position is %d\n", k, arr[k]); 
}

void getIndex(int* arr, int n, int k) {
	int flag = 0;
	for(int i=0;i<n;i++) {
		if(arr[i] == k) {
			flag = 1;
			printf("%d, ", i);
		}
	}
	if(flag == 0)
		printf("\nElement not found");
}

void reverse(int* arr, int n) {
	int start = 0, end = n-1;
	while(start < end) {
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

void count(int n) {
	printf("\nThe size of array is: %d\n", n);
}

void display(int* arr, int n) {
	printf("\nThe array elements are:\n");
	for(int i=0;i<n;i++)
		printf("%d, ", arr[i]);
	printf("\n");
}

int* create(int n) {
	int* a = (int*)malloc(sizeof(int)*n);
	printf("\nEnter %d, elements\n", n);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	return a;
}

