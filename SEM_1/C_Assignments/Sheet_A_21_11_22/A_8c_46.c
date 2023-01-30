/*
    program to compute log(1+x)
    = x - (x^2/2) + (x^3/3) - (x^4/4) ..... where -1 < x <= 1
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int n = 100000, i, j, sign = 1;
    double x, res=0, term;
    printf("\nEnter the value of X: ");
    scanf("%lf", &x);
    
    i = 1;
    while(i <= n) {
        term = pow(x, i)/i;
        res += sign*term;
        i++;
        sign *= -1;
    }
    
    printf("%lf", res);
}