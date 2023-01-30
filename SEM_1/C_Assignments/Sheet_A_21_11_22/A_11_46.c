#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double nThFibo(int n)
{
    if(n <= 2)
        return (double)n;
    double a = 1, b = 1, term = 0;
    int i = 1;
    for(i=3;i<=n;i++) {
        term = a + b;
        a = b;
        b = term;
    }
    return term;
}

double fiboFormula(int n)
{
    double root = sqrt(5);
    double termA = 0, termB = 0;
    termA = pow(((1+root)/2), n) * (1/root);
    termB = pow(((1-root)/2), n) * (1/root);
    termA = termA - termB;
    return termA;
}

int main()
{
    int n;
    double fromSeries = 0, fromFormula = 0;
    printf("\nEnter n: ");
    scanf("%d", &n);

    fromSeries = nThFibo(n);
    printf("\nThe %d'th fibonacci number from series is: %lf", n, fromSeries);

    fromFormula = fiboFormula(n);
    printf("\nThe %d'th fibonacci number from formula is: %lf", n, fromSeries);

    double diff = fromSeries - fromFormula;
    printf("\n%le", diff);
}