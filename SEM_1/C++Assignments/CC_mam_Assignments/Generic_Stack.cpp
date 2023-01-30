#include "Generic_Stack.hpp"
#include "TIME.hpp"

int main() {
    Generic_Stack<TIME, 10> myStack;
    TIME temp;
    int depth;
    int choice;
    std::cout<<"\nThis is a stack which sotres TIME type data";

    while(1) {
        std::cout<<"\n1 -> push item";
        std::cout<<"\n2 -> pop item";
        std::cout<<"\n3 -> peek";
        std::cout<<"\n4 -> display all items";
        std::cout<<"\n5 -> element at given depth";
        std::cout<<"\n6 -> exit";
        std::cout<<"\nEnter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout<<"\nEnter element to push: ";
            std::cin >> temp;
            myStack.push(temp);
            break;
        case 2:
            temp = myStack.pop();
            std::cout<<"\nPopped element is: "<<temp;
            break;
        case 3:
            myStack.peek();
            break;
        case 4:
            myStack.display();
            break;
        case 5:
            std::cout<<"\nEnter depth of element: ";
            std::cin >> depth;
            myStack.display(depth);
            break;
        case 6:
            return 0;
        default:
            break;
        }

    }
}