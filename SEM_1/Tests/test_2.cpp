#include <iostream>

class a {
public:
    int i = 1;
    // a() { std::cout<<"\n A"; }
    void print() { std::cout<<"from A : " <<"\n"; }
};

class b : public a {
public:
    b () { 
        i = 2;
        // std::cout<<"\n B";
    }
    void print() { std::cout<<"\nfuck"; }
    void print(int x) { std::cout<<"from B : "<< x <<"\n"; }
};



int main() 
{
    a *p;
    a a1;
    b b1;

    p = &a1;
    p->print();

    p = &b1;
    p->print();

}