#include <stdio.h>

void strcat(char* a, const char* b) {
    char *temp = a;
    while(*temp != '\0')
        temp++;
    while(*b != '\0')
        *temp++ = *b++;
    *temp = '\0';
}

int main()
{
    char a[] = "hello ";
    char b[] = "world";

    strcat(a, b);
    printf("%s", a);
}