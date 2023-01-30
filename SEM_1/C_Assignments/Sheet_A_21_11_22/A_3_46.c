#include <stdio.h>

int main()
{
    int n;
    int i,j;
    int firstSum, lastSum;

    printf("\nEnter the number of rooms: ");
    scanf("%d", &n);
    i = 1;
    int total = n*(n+1)/2;

    for(i=1; i<=n; i++)
    {
        int num = i-1;
        firstSum = num*(num+1)/2;
        lastSum = total - firstSum - i;
        //printf("\nfirstSum = %d", firstSum);
        //printf("\nlastSum = %d", lastSum);

        if(firstSum == lastSum)
            printf("\n%d\n ", i);
        
        //sleep(1);
    }

    printf("\nNothing");
    return 0;
}