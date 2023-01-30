//permutation of n numbers
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *n, int f, int l) {
    int i;
    if(f == l)
        puts(n);
    else
    for(i=f;i<=l;i++) {
        swap(n+f, n+i);
        permute(n, f+1, l);
        swap(n+f, n+i);
    }
}

int main()
{
    char n[50];
    printf("Enter the number: ");
    scanf("%s", &n);

    permute(n, 0, strlen(n) - 1);
    
}