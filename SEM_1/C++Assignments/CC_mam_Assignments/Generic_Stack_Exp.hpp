#include <iostream>
#include <string>

class customStackException {
private:
    std::string message;
public:
    customStackException(const std::string& message) {
        this->message = message;
    }
    std::string what() const {
        return message;
    }
};


//template stack class
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
    T getStackAvg(void);
};

template <typename T, int N> 
T Generic_Stack<T, N>::getStackAvg() {
    if(top < 0)
        throw customStackException("Stack underflow");
    int temp = 0;
    for(int i=0;i<=top;i++)
        temp = temp + stack[i];
    temp /= top+1;
    return T(temp);
}

template <typename T, int N> 
void Generic_Stack<T, N>::push(const T& value) {
    if(top == N - 1)
        throw customStackException("Stack Overflow");
    top++;
    stack[top] = value;
}

template <typename T, int N>
void Generic_Stack<T, N>::peek() {
    if(top == -1) 
        throw customStackException("Stack underflow");
    std::cout<<"\nTop of stack is: "<<stack[top];
}

template <typename T, int N>
T Generic_Stack<T, N>::pop() {
    if(top < 0)
        throw customStackException("Stack underflow");
    int x = stack[top];
    top--;
    return x;
}

template <typename T, int N>
void Generic_Stack<T, N>::display() {
    if(top < 0) 
        throw customStackException("Stack underflow");
    std::cout<<"\nStack elements are:\n";
    for(int i=0;i<=top;i++)
        std::cout<<stack[i]<<" ,";
}

template <typename T, int N>
void Generic_Stack<T, N>::display(const int& depth) {
    if(depth < 0 || depth > top) 
        throw customStackException("Invalid Depth");
    std::cout<<"\nElement at depth "<<depth<<" is: "<<stack[top - depth];
}