#include "Generic_Stack_Exp.hpp"

int main() {
    Generic_Stack<char, 10> myStack;
    char temp;
    int depth;
    int choice;

    while(1) {
        std::cout<<"\n1 -> push item";
        std::cout<<"\n2 -> pop item";
        std::cout<<"\n3 -> peek";
        std::cout<<"\n4 -> display all items";
        std::cout<<"\n5 -> element at given depth";
        std::cout<<"\n6 -> get stack average";
        std::cout<<"\n7 -> exit";
        std::cout<<"\nEnter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout<<"\nEnter element to push: ";
            std::cin >> temp;
            try {
                myStack.push(temp);
            }
            catch (const customStackException& e) {
                std::cout<<"\nException: "<<e.what();
            }
            break;
        case 2:
            try {
                temp = myStack.pop();
                std::cout<<"\nPopped element is: "<<temp;
            }
            catch (const customStackException& e) {
                std::cout<<"\nException: "<<e.what();
            }
            break;
        case 3:
            try {
                myStack.peek();
            }
            catch (const customStackException& e) {
                std::cout<<"\nException: "<<e.what();
            }
            break;
        case 4:
            try {
                myStack.display();
            }
            catch (const customStackException& e) {
                std::cout<<"\nException: "<<e.what();
            }
            break;
        case 5:
            std::cout<<"\nEnter depth of element: ";
            std::cin >> depth;
            try {
                myStack.display(temp);
            }
            catch (const customStackException& e) {
                std::cout<<"\nException: "<<e.what();
            }
            break;
        case 6:
            try {
                temp = myStack.getStackAvg();
                std::cout<<"\n"<<temp;
            }
            catch (const customStackException& e) {
                std::cout<<"\nException: "<<e.what();
            }
            break;
        case 7:
            return 0;
        default:
            break;
        }

    }
}