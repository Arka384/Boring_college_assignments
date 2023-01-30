#include <iostream>
constexpr int MAX_SIZE= 100;

class CustomStack {
private:
    int stack[MAX_SIZE];
    int top;

public:
    CustomStack() { top = -1; }
    int getTop() { return top; }
    void push(const int& value);
    void peek(void);
    int getPeek(void);
    int pop(void);
    void display(void);
    void display(const int& depth);
};

void CustomStack::push(const int& value) {
    if(top == MAX_SIZE - 1) {
        std::cout<<"\nStack overflow";
        return;
    }
    top++;
    stack[top] = value;
}

void CustomStack::peek() {
    if(top == -1) {
        std::cout<<"\nStack underflow";
        return;
    }
    std::cout<<"\nTop of stack is: "<<stack[top];
}

int CustomStack::getPeek() {
    if(top == -1)
        return INT32_MAX;
    return stack[top];
}

int CustomStack::pop() {
    if(top < 0) {
        std::cout<<"\nStack underflow";
        return INT32_MAX;
    }
    int x = stack[top];
    top--;
    return x;
}

void CustomStack::display() {
    if(top < 0) {
        std::cout<<"Stack Empty";
        return;
    }
    // std::cout<<"\nStack elements are:\n";
    for(int i=0;i<=top;i++)
        std::cout<<stack[i]<<" ,";
}

void CustomStack::display(const int& depth) {
    if(depth < 0 || depth > top) {
        std::cout<<"\nInvalid depth";
        return;
    }
    std::cout<<"\nElement at depth "<<depth<<" is: "<<stack[top - depth];
}