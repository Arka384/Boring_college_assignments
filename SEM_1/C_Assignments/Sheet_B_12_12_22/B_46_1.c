#include <stdio.h>
#include <limits.h>
#include <malloc.h>

int findMax(int *arr, int size, int upTo) {
    int currMaxIndex = 0;
    int currMax = INT_MIN;
    int t=1, i;
    while(t <= upTo) {
        currMax = INT_MIN;
        for(i=0;i<size;i++) {
            if(*(arr+i) > currMax) {
                currMax = *(arr+i);
                currMaxIndex = i;
            }
        }
        *(arr + currMaxIndex) = INT_MIN;
        t++;
    }
    return currMax;
}

int findMin(int *arr, int size, int upTo) {
    int currMinIndex = 0;
    int currMin = INT_MAX;
    int t=1, i;
    while(t <= upTo) {
        currMin = INT_MAX;
        for(i=0;i<size;i++) {
            if(*(arr+i) < currMin) {
                currMin = *(arr+i);
                currMinIndex = i;
            }
        }
        *(arr + currMinIndex) = INT_MAX;
        t++;
    }
    return currMin;
}

int main()
{
    int n,i;
    int *arr, *copy1, *copy2;

    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("\nEnter array elements: ");
    arr = (int* )malloc(sizeof(int )*n);
    copy1 = (int* )malloc(sizeof(int )*n);
    copy2 = (int* )malloc(sizeof(int )*n);
    for(i=0;i<n;i++) {
        scanf("%d", &*(arr+i));
        *(copy1 + i) = *(arr + i);
        *(copy2 + i) = *(arr + i);
    }
        
    printf("\nThird max element is: %d", findMax(copy1, n, 3));
    printf("\nFifth min element is: %d", findMin(copy2, n, 5));
    printf("\nMiddle element is: %d", *(arr + n/2));

    return 0;
}