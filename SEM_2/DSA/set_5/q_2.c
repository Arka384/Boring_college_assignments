#include <stdio.h>
#include <malloc.h>

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        // Shift elements greater than key to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        // Find the index of the minimum element in the remaining unsorted part
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // Swap arr[i] with the minimum element
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}



int main() {
    int *arr;
    int size, choice;

    printf("\nEnter the size of the array: ");
    scanf("%d", &size);
    arr = (int*)malloc(sizeof(int)*size);
    printf("\nEnter the array elements:\n");
    for(int i=0; i<size; i++)
        scanf("%d", &arr[i]);
    
    while (1) {
        printf("\n1 -> bubble sort\n2 -> insertion sort\n3 -> selection sort\n4 -> exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bubbleSort(arr, size);
            break;
        case 2:
            insertionSort(arr, size);
            break;
        case 3:
            selectionSort(arr, size);
            break;
        case 4:
            return 0;
        default:
            break;
        }

        printf("\nSorted array: \n");
        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    
    return 0;
}

