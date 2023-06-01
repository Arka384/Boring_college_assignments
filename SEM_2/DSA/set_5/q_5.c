#include <stdio.h>
#include <malloc.h>

void mergeSort(int* , int, int );
void merge(int* , int, int , int);
void quickSort(int* , int, int);
int partition(int* , int, int);

int main()
{
    int *arr;
    int size;
    
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);
    arr = (int*)malloc(sizeof(int)*size);
    printf("\nEnter the array elements:\n");
    for(int i=0; i<size; i++)
        scanf("%d", &arr[i]);
    
    //mergeSort(arr, 0, size - 1);
    //quickSort(arr, 0, size - 1);

    printf("\nSorted array: \n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

}

void quickSort(int* arr, int start, int end) {
    int pivot;
    if(start < end) {
        pivot = partition(arr, start, end);
        //pivot is in the correct position, thats why (pivot + 1) and (pivot - 1)
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

int partition(int* arr, int start, int end) {
    int pivot = arr[start];
    int left = start + 1;   //as start is pivot
    int right = end;

    while(left <= right) {
        while(arr[left] < pivot && left < right)
            left++;
        while(arr[right] > pivot)
            right--;
        if(left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        else
            left++;
    }

    arr[start] = arr[right];
    arr[right] = pivot;
    return right;
}

void mergeSort(int* arr, int start, int end) {
    int mid;
    if(start != end) {
        mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

void merge(int* arr, int start, int mid, int end) {
    int s = mid + 1;
    int first = start, last = end;
    int temp[50], tIndex = 0;

    while(first <= mid && s <= end) {
        if(arr[first] <= arr[s]) {
            temp[tIndex++] = arr[first++];
        }
        else {
            temp[tIndex++] = arr[s++];
        }
    }

    while (first <= mid) {
        temp[tIndex++] = arr[first++];
    }
    while(s <= end) {
        temp[tIndex++] = arr[s++];
    }

    for(int k = 0,i = start; i <= end; i++, k++)
        arr[i] = temp[k];

}