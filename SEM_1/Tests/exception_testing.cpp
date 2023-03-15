#include <iostream>
#include <string>
#include <stdexcept>

void fun_a(int a)
{
    throw 10;
    std::cout<<a<<std::endl;
}

int main()
{
    // try {
        fun_a(25);
    // }
    // catch(const std::invalid_argument& e) {
    //     std::cout<<e.what()<<std::endl;
    // }
}