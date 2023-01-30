/*
    program to compute e
    = 1/1! + 2/2! + 3/3! + .....
*/

#include <stdio.h>
#include <math.h>

double facto(int n) {
    int i=1;
    double fact = 1;
    for(i=1;i<=n;i++)
        fact *= i;
    return fact;
}

int main()
{
    int n, i;
    double res=0, term;
    printf("\nEnter the value: ");
    scanf("%d", &n);
    
    i = 1;
    while(i <= n) {
        term = i/facto(i);
        res += term;
        i++;
    }

    printf("%lf", res);
}