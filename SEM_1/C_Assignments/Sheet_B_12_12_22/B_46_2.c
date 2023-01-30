#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void randomPartition(int [], int );

int main()
{
    srand(time(NULL));
    int arr[100], n, i;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("\nEnter n elements: ");
    for(i=0;i<n;i++)
       scanf("%d", &arr[i]);

    randomPartition(arr, n);
}

void randomPartition(int arr[], int n)
{
    int partA[50], partB[50], i, j, k;
    int x = rand()%n;
    int randVal = arr[x];
    printf("%d\n", randVal);

    for(i=0,j=0,k=0;i<n;i++) {
        if(arr[i] < randVal)
            partA[j++] = arr[i];
        else if(arr[i] > randVal)
            partB[k++] = arr[i];
    }

    printf("\n");
    for(i=0;i<j;i++)
        printf("%d, ", partA[i]);
    printf("\n");
    for(i=0;i<k;i++)
        printf("%d, ", partB[i]);  

}