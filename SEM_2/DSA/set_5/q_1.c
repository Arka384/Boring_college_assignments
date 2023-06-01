#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  // Found the key at index i
        }
    }
    return -1;  // Key not found in the array
}
#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;  // Found the key at index mid
        } else if (arr[mid] < key) {
            low = mid + 1;  // Key is in the right half of the array
        } else {
            high = mid - 1;  // Key is in the left half of the array
        }
    }

    return -1;  // Key not found in the array
}

int main() {
    int arr[50];
    int size = sizeof(arr) / sizeof(arr[0]);
    int key, choice, index = -1;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("\nEnter the array elements: ");
    for(int i=0;i<size;i++)
        scanf("%d", &arr[i]);
    
    while(1) {
        printf("\n1 -> linear search\n2 -> binary search\n3 -> exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if(choice != 3) {
            printf("\nEnter the element you wish to search: ");
            scanf("%d", &key);
        }
        switch (choice)
        {
        case 1:
            index = linearSearch(arr, size, key);
            break;
        case 2:
            index = binarySearch(arr, size, key);
            break;
        case 3:
            return 0;
        default:
            break;
        }
        if (index != -1)
            printf("Element found at index %d\n", index);
        else
            printf("Element not found in the array\n");
    }

}
