#include <stdio.h>

long int gcd(long int a, long int b) {
    if (b == 0) 
        return a;
    return gcd(b, a%b);
}

int main()
{
    int a,b;
    printf("Enter two numners: ");
    scanf("%d %d", &a, &b);

    if(a == 0 || b == 0) {
        printf("\nUndefined");
        return 0;
    }
    printf("\nGCD of %d and %d is: %d", a, b, gcd(a,b));
}