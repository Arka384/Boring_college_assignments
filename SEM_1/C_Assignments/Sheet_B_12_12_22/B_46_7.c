#include <stdio.h>

int strLen(const char *str) {
    int i = 0;
    while(*(str+i) != '\0')
        i++;
    return i;
}

char *strCpy(char *strA, const char *strB) {
    int i = 0;
    while(*(strB + i) != '\0') {
        *(strA + i) = *(strB + i);
        i++;
    }
    *(strA + i) = '\0';
    return strA;
}

char *strCat(char *strA, const char *strB) {
    int i = 0, j = 0;
    while(*(strA + i) != '\0')
        i++;
    *(strA + i++) = ' ';
    while(*(strB + j) != '\0')
        *(strA + i++) = *(strB + j++);
    *(strA + i) = '\0';
    return strA;
}

char *strRev(char *str) {
    int len = strLen(str)-1;
    int i = 0;
    char temp;
    while(len > i) {
        temp = *(str + i);
        *(str + i) = *(str + len);
        *(str + len) = temp;
        i++;
        len--;
    }
    return str;
}

int strCmp(const char *strA, const char *strB) {
    int i=0, j=0;
    while(*(strA + i) != '\0' && *(strB + j) != '\0') {
        if(*(strA + i) > *(strB + j))
            return 1;
        if(*(strA + i) < *(strB + j))
            return -1;
        i++;
        j++;
    }

    if(*(strA + i) != '\0')
        return 1;
    if(*(strB + j) != '\0')
        return -1;
    return 0;
}


int main()
{
    char strA[100], strB[100];
    int choice;

    while(1) {
        printf("\n1 -> Strlen()");
        printf("\n2 -> Strcpy()");
        printf("\n3 -> Strcat()");
        printf("\n4 -> Strrev()");
        printf("\n5 -> Strcmp()");
        printf("\n6 -> To Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        fflush(stdin);
        switch (choice)
        {
        case 1:
            printf("\nEnter string: ");
            gets(strA);
            printf("\nThe length is: %d", strLen(strA));
            break;
        case 2:
            printf("\nEnter first string: ");
            gets(strA);
            printf("\nEnter second string: ");
            gets(strB);
            printf("\nThe first string becomes: %s", strCpy(strA, strB));
            break;
        case 3:
            printf("\nEnter first string: ");
            gets(strA);
            printf("\nEnter second string: ");
            gets(strB);
            printf("The first string becomes: %s", strCat(strA, strB));
            break;
        case 4:
            printf("\nEnter string: ");
            gets(strA);
            printf("\nThe reversed string is: %s", strRev(strA));
            break;
        case 5:
            printf("\nEnter first string: ");
            gets(strA);
            printf("\nEnter second string: ");
            gets(strB);
            printf("\nThe result of comparison is: %d", strCmp(strA, strB));
            break;
        case 6:
            return 0;
        default:
            break;
        }
    }

    return 0;    
}