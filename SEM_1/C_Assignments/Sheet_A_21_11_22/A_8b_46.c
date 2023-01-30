/*
    program to compute cos(x)
    = 1 - (x^2/2!) + (x^4/4!) - (x^6/6!) .....
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
    int n = 50, i, j, sign = 1;
    double x, res=0, term;
    printf("\nEnter the value of X: ");
    scanf("%lf", &x);
    
    i = 1, j = 0;
    while(i <= n) {
        term = pow(x, j)/facto(j);
        res += sign*term;
        i++;
        j+=2;
        sign *= -1;
    }
    if(res <= 0)
        res = 0;
    printf("%lf", res);
}