#include <iostream>

class myNum {
private:
    int a;
public:
    myNum() {}
    myNum(int x) { this->a = x; }
    
    // //this is one way of doing operator overloading
    // //in this case we can access the myNum class
    // myNum operator + (const myNum& ob) {
    //     myNum x;
    //     x.a = this->a + ob.a;
    //     return x;
    // } 

    //this is another way of doing operator overloading
    friend myNum operator + (const myNum& ob1, const myNum& ob2);
    friend std::ostream& operator << (std::ostream& out_stream, const myNum& ob);
};

myNum operator + (const myNum& ob1, const myNum& ob2) {
    myNum x;
    x.a = ob1.a + ob2.a;
    return x;
}

std::ostream& operator << (std::ostream& out_stream, const myNum& ob) {
    out_stream << ob.a;
    return out_stream;
}

int main()
{
    myNum a(10);
    myNum b(25);

    myNum x = a + b;
    
    std::cout<<x;

    return 0;
}