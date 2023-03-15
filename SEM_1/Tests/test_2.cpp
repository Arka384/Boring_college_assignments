#include <iostream>

class shape {
public:
    virtual void print() { std::cout<<"Shape"; }
};

class circle : public shape{
public:
    void print() { std::cout<<"Circle"; }   
};

class square : public shape{
public:
    void print() { std::cout<<"Square"; }   
};

class ellipse : public shape{
public:
    void print() { std::cout<<"Ellipse"; }   
};

void invoke_Print(shape* shapeObj) {
    shapeObj->print();
}

int main() 
{
    circle c;
    square s;
    ellipse e;
    shape *sp;
    sp = &e;

    sp->print();

    invoke_Print(sp);
}