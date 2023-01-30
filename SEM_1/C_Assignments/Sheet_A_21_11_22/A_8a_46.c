/*
    program to compute sin(x)
    = x - (x^3/3!) + (x^5/5!) - (x^7/7!) .....
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
    int n = 20, i, j, sign = 1;
    double x, res=0, term;
    printf("\nEnter the value of X: ");
    scanf("%lf", &x);
    
    i = j = 1;
    while(i <= n) {
        term = pow(x, j)/facto(j);
        res += sign*term;
        i++;
        j+=2;
        sign *= -1;
    }

    printf("%lf", res);
}