#include <stdio.h>

void function(int a) {  //function with single int param
    printf("Value = %d\n", a);
}
float calc(int a, int b, float f) { //function with 2 int param and a float param
    return ((float)a / (float)b)*f;
}
//function which takes 2 function pointers as parameters
void wrapper(void (*f_ptr_1)(int), float (*f_ptr_2)(int, int, float)) {
    f_ptr_1(5);
    float temp = (*f_ptr_2)(5, 6, 2.5);
    printf("%f", temp);
}

int main()
{
    void (*fun_ptr_1)(int ) = &function;
    // void (*f_ptr)(int) = function;
    // (*fun_ptr)(10);
    // f_ptr(20);

    float (*fun_ptr_2)(int, int, float) = &calc;
    // float temp = (*fun_ptr)(5, 6, 2.5);
    // printf("%f", temp);

    wrapper(fun_ptr_1, fun_ptr_2);
}