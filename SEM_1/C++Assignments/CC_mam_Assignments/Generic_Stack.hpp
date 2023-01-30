#include <iostream>

template <typename T, int N>
class Generic_Stack {
private:
    T stack[N];
    int top;
public:
    Generic_Stack() { top = -1; }
    int getTop() { return top; }
    void push(const T& value);
    void peek(void);
    T pop(void);
    void display(void);
    void display(const int& depth);
};

template <typename T, int N> 
void Generic_Stack<T, N>::push(const T& value) {
    if(top == N - 1) {
        std::cout<<"\nStack overflow";
        return;
    }
    top++;
    stack[top] = value;
}

template <typename T, int N>
void Generic_Stack<T, N>::peek() {
    if(top == -1) {
        std::cout<<"\nStack underflow";
        return;
    }
    std::cout<<"\nTop of stack is: "<<stack[top];
}

template <typename T, int N>
T Generic_Stack<T, N>::pop() {
    T x = stack[top];
    top--;
    return x;
}

template <typename T, int N>
void Generic_Stack<T, N>::display() {
    if(top < 0) {
        std::cout<<"\nStack underflow";
        return;
    }
    std::cout<<"\nStack elements are:\n";
    for(int i=0;i<=top;i++)
        std::cout<<stack[i]<<" ,";
}

template <typename T, int N>
void Generic_Stack<T, N>::display(const int& depth) {
    if(depth < 0 || depth > top) {
        std::cout<<"\nInvalid depth";
        return;
    }
    std::cout<<"\nElement at depth "<<depth<<" is: "<<stack[top - depth];
}