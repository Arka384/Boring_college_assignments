#include <stdio.h>

void fun(int* a, int* b) {
    a = b;
    *a = 2;
    *b = 4;
}

int main() {
    int a = 5, b = 6;
    fun(&a, &b);
    printf("%d, %d", a, b);
}