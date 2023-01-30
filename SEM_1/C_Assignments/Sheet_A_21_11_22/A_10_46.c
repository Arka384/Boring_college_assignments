#include <stdio.h>
#include <string.h>

void reverse(char *number, char *reversed, int *size)
{
    int i,j;
    for(i=*size-1,j=0;i>=0;i--,j++)
        *(reversed + j) = *(number + i);
}

void trucn(char *number, int *size)
{
    int i=0,j;
    while(i < *size) {
        if(*(number+i) != '0')
            break;
        i++;
    }

    if(i==0)
        return;

    for(j=i;j<*size;j++)
        *(number+(j-i)) = *(number+j);
    *size = *size - i;
    *(number+(*size)) = '\0';
}

int main()
{
    char number[50] = {' '}, reversed[50] = {' '};
    int i, n = 0;

    printf("\nEnter the number: ");
    scanf("%s", &number);
    n = strlen(number);

    trucn(number, &n);
    reverse(number, reversed, &n);
    trucn(reversed, &n);

    printf("\nThe reversed number is: ");
    printf("\n%s", reversed);

    if(strcmp(number, reversed) == 0)
        printf("\nThe number is palindrome");
    else
        printf("\nThe number is NOT palindrome");

    return 0;
}