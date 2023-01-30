#include <stdio.h>

char *single_digit[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *double_digit[] = {"", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char *double_digit_special[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *hundredIndian[] = {"", "hundred", "thousand", "lakh", "crore"};
char *hundredInternational[] = {"", "hundred", "thousand", "million"};

void printTwoDigit(int num)
{
    if (num < 10)
    {
        printf("%s ", single_digit[num]);
    }
    else if (num < 20)
    {
        printf("%s ", double_digit_special[num % 10]);
    }
    else
    {
        printf("%s ", double_digit[num / 10]);
        if (num % 10 != 0)
        {
            printf("%s ", single_digit[num % 10]);
        }
    }
}

void printThreeDigit(int num, char *hundred[])
{
    int hundredDigit = num / 100;
    if (hundredDigit > 0)
    {
        printf("%s %s ", single_digit[hundredDigit], hundred[1]);
    }
    printTwoDigit(num % 100);
}
void printIndian(int num)
{
    // print crore
    printf("%s %s ", single_digit[num / 10000000], hundredIndian[4]);
    num = num % 10000000;

    // print lakh
    int lakh = num / 100000;
    num = num % 100000;
    if (lakh > 0)
    {
        printTwoDigit(lakh);
        printf("%s ", hundredIndian[3]);
    }

    // print thousand
    int thousand = num / 1000;
    num = num % 1000;
    if (thousand > 0)
    {
        printTwoDigit(thousand);
        printf("%s ", hundredIndian[2]);
    }

    // print hundred
    int hundred = num / 100;
    num = num % 100;
    if (hundred > 0)
    {
        printTwoDigit(hundred);
        printf("%s ", hundredIndian[1]);
    }

    // print last two digit
    printTwoDigit(num);
}

void printInternational(int num)
{

    // print million
    int million = num / 1000000;
    num = num % 1000000;
    if (million > 0)
    {
        printTwoDigit(million);
        printf("%s ", hundredInternational[3]);
    }

    // print thousand
    int thousand = num / 1000;
    num = num % 1000;
    if (thousand > 0)
    {
        printThreeDigit(thousand, hundredInternational);
        printf("%s ", hundredInternational[2]);
    }

    // print hundred
    printThreeDigit(num, hundredInternational);
}
int main()
{
    int num;
    printf("Enter the 8-digit number: ");
    scanf("%d", &num);
    printf("The number in Indian number system : \n ");
    printIndian(num);
    printf("\n");
    printf("The number in International number system : \n ");
    printInternational(num);
    printf("\n");
}