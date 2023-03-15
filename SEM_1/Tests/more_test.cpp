#include <iostream>

class Base {
    int a, b;
public:
    Base() = default;
    Base(int a, int b) {
        std::cout<<"\nBase";
        this->a = a;
        this->b = b;
    }
    void show() { std::cout<<a<<" "<<b<<std::endl; }
};

class Derived : public Base {
public:
    Derived(int a, int b) : Base(a, b)
    {
        std::cout<<"\nDerived";
    }
};

int main()
{
    Derived a(6, 7);
    a.show();
}