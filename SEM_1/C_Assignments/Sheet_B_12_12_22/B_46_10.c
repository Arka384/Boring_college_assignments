#include <stdio.h>
#include <malloc.h>

int findInString(char *strA, char *strB) {
    int i = 0, k = 0, index = 0;
    while(strA[i] != '\0') {
        if(strA[i] == strB[k]) {
            index = i;
            while(strA[i] == strB[k]) {
                i++;
                k++;
            }
            if(strB[k] == '\0')
                return index;
        }
        i++;
        k = 0;
        index = 0;
    }
    return index;
}

int main()
{
    char *strA, *strB;
    int strCapacity = 100;
    int foundInIndex = 0;

    strA = (char *)malloc(sizeof(char) * strCapacity);
    strB = (char *)malloc(sizeof(char) * strCapacity);

    printf("Enter first string: ");
    gets(strA);
    printf("\nEnter second string: ");
    gets(strB);

    foundInIndex = findInString(strA, strB);
    if(foundInIndex != 0)
        printf("\nSecond string found from index: %d", foundInIndex);
    else
        printf("\nSecond string not present in first string");
    
    return 0;
}