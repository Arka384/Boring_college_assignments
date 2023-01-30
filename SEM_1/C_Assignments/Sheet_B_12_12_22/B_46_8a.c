#include <stdio.h>

void fiboRec(int a, int b, int n) {
    if(n == 0)
        return;
    int third = a + b;
    printf("%d, ", third);
    fiboRec(b, third, n-1);
}

int main()
{
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    if(n == 0) {
        printf("\nNo series");
    }
    else if(n == 1)
        printf("0, ");
    else if (n == 2)
        printf("0, 1, ");
    else {
        printf("0, 1, ");
        fiboRec(0,1,n-2);
    }
        
    return 0;
}