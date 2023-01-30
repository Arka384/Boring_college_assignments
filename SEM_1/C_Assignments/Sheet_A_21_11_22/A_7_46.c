#include <stdio.h>

long int gcd(long int a, long int b) {
    if (b == 0) 
        return a;
    return gcd(b, a%b);
}

long long int lcm(int a[], int n) {
    long long int res = 1, i;
    for (i = 0; i < n; i++) {
        res = res*a[i]/gcd(res, a[i]);
    }
    return res;
}

int main()
{
    int n,i;
    int arr[50];
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
        if(arr[i] == 0) {
            printf("\nUndefined");
            return 0;
        }
    }
        

    printf("\n%lld", lcm(arr, n));
}