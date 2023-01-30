/*
    to find: 2*3 + 3*5 + 5*7 + ....
*/

#include <stdio.h>

int prime(int n) {
    int c = 0, i = 1;
    for(i = 1;i <= n;i++)
        if(n % i == 0)
            c++;
    if(c == 2)
        return 0;
    else
        return 1;
}

int main()
{
    int n, i;
    int a = 2, b = 3;
    long int res = 0;
    printf("\nEnter the value of n: ");
    scanf("%d", &n);

    i = 1;
    while(i <= n) {
        res += a*b;
        //printf("\n%d, %d", a, b);
        a++;
        while(prime(a))
            a++;
        b++;
        while(prime(b))
            b++;
        i++;
    }

    printf("%ld", res);
}