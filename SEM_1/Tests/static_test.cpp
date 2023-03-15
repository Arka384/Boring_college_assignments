#include <iostream>

class num {
    int a;
public:
    num() = default;
    num(const int& a) {
        this->a = a;
    }
    void show() { std::cout<<a<<std::endl; }
};

int main()
{
    num a;
    a.show();
}