/*sum of all digits of num*/
#include <stdio.h>

int sumDigits(int number) {
    if(number <= 0)
        return 0;

    return (number%10) + sumDigits(number/10);
}

int main()
{
    int num, copy;
    printf("Enter the number: ");
    scanf("%d", &num);
    copy = num;
    
    printf("\nSum of digits of %d is : %d", num, sumDigits(num));
}