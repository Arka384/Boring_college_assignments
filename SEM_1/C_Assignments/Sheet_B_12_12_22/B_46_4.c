#include <stdio.h>
#include <string.h>

void reverseIter(char [], int );
void reverseRec(char [], int );

int main()
{
    char str[50];
    int len;

    printf("Enter the string: ");
    gets(str);
    len = strlen(str);

    printf("\n");
    reverseIter(str, len);
    printf("\n");
    reverseRec(str, len);
    
}

void reverseIter(char str[], int len) {
    while(len >= 0) {
        printf("%c", str[len]);
        len--;
    }
}

void reverseRec(char str[], int len) {
    printf("%c", str[len]);

    if(len == 0)
        return;

    reverseRec(str, len-1);
}