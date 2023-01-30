#include "CustomStack.hpp"

class DescendingStack : public CustomStack {
public:
    DescendingStack() { }

    DescendingStack(CustomStack s) {
        //constructor for creating sorted stack from normal custom stack
        int a[MAX_SIZE], k=0;
        while(s.getTop() >= 0) {
            int x = s.pop();
            a[k] = x;
            k++;
        }
        
        //now sort and push in new Descending stack
        for(int i=0;i<k;i++)
            for(int j=0;j<k-i-1;j++)
                if(a[j] < a[j+1])
                    std::swap(a[j], a[j+1]);

        for(int i=0;i<k;i++)
            this->push(a[i]);
    
    }

    void push(const int& value) {
        if(getTop() == -1)
            CustomStack::push(value);
        else if(getPeek() > value)
            CustomStack::push(value);
        else
            std::cout<<"\nInvalid input";
    }

};
