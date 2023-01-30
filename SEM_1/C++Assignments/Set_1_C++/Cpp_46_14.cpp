#include <iostream>

class Number {
private:
    int n;
public:
    Number() {}
    Number(int n) { this->n = n; }
    int getNumber() { return this->n; }
    void setNumber(int n) { this->n = n; }

    friend void swap(Number& a, Number& b);
};

void swap(Number& a, Number& b) {
    a.n = a.n + b.n;
    b.n = a.n - b.n;
    a.n = a.n - b.n;
}

int main()
{
    Number *a = new Number(20);
    Number *b = new Number(6);
    std::cout<<"\nBefore swapping the numbers are: " << a->getNumber() << " , " << b->getNumber();
    swap(*a, *b);
    std::cout<<"\nAfter swapping the numbers are: " << a->getNumber() << " , " << b->getNumber();
}