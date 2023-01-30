#include <stdio.h>
#include <math.h>

int toBinary(int decimal, int *arr) {
    int i,j=0;
    for(i = 31; i >= 0; i--) {
        int k = decimal >> i;
        if(k & 1)
            *(arr+j) = 1;
        else
            *(arr+j) = 0;
        j++;
    }
    return j;
}

void displayBinary(int *arr, int size) {
    printf("\nBinary equivalant is: ");
    int i = 0;
    while(*(arr+i) == 0)
        i++;
    while(i < size) {
        printf("%d", *(arr+i));
        i++;
    }       
}

int main()
{
    int number;
    int binary[32] = {0}, size;
    
    printf("Enter the decimal number: ");
    scanf("%d", &number);

    size = toBinary(number, binary);
    displayBinary(binary, size);

    return 0;
}