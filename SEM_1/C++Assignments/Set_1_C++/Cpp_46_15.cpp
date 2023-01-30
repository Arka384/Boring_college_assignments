#include <iostream>

class Complex {
private:
    int real, img;
public:
    Complex() {};
    Complex(const Complex& object) {
        this->real = object.real;
        this->img = object.img;
    }
    Complex(const int& real, const int& img) {
        this->real = real;
        this->img = img;
    }
    void show() {
        std::cout<<this->real<<" + i"<<this->img<<"\n";
    }

    friend Complex sum(const Complex& a, const Complex& b);

};

Complex sum(const Complex& a, const Complex& b) {
    Complex temp;
    temp.real = a.real + b.real;
    temp.img = a.img + b.img;
    return temp;
}


int main()
{
    Complex *a = new Complex(10, 12);
    Complex *b = new Complex(6, 8);
    std::cout<<"\nComplex number a: ";
    a->show();
    std::cout<<"\nComplex number b: ";
    b->show();

    Complex c = sum(*a, *b);
    std::cout<<"\na + b = ";
    c.show();
}