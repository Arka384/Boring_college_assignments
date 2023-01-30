#include "CustomStack.hpp"

int main() {
    CustomStack *myStack = new CustomStack();
    int choice, temp;

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
            myStack->push(temp);
            break;
        case 2:
            temp = myStack->pop();
            if(temp != INT32_MAX)
                std::cout<<"\nPopped element is: "<<temp;
            break;
        case 3:
            myStack->peek();
            break;
        case 4:
            myStack->display();
            break;
        case 5:
            std::cout<<"\nEnter depth of element: ";
            std::cin >> temp;
            myStack->display(temp);
            break;
        case 6:
            return 0;
        default:
            break;
        }

    }
}