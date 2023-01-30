#include <iostream>
#include <algorithm>
#include <iterator>

class NumberList {
private:
    int *arr;
    int size;

public:
    NumberList() {}
    NumberList(int size) {
        this->size = size;
        arr = new int[size];
    }

    void setSize(int size) {
        this->size = size;
        arr = new int[size];
    }

    void setElements() {
        std::cout<<"\nInsert "<<this->size<<" elements: ";
        for(int i=0;i<size;i++)
            std::cin>>*(arr + i);
    }

    int& findMin() {
        return *std::min_element(arr, arr+(size-1));
    }

    int& findMax() {
        return *std::max_element(arr, arr+(size-1));
    }

    void sort() {
        for(int i=0;i<size;i++) {
            for(int j=0;j<size-i-1;j++)
                if(arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
        }
    }

    void display() {
        std::cout<<"\nThe array is: ";
        for(int i=0;i<size;i++)
            std::cout<<*(arr+i)<<" ";
        std::cout<<"\n";
    }

};


int main()
{
    NumberList *list = new NumberList();
    int x;
    
    std::cout<<"Enter the size of the array: ";
    std::cin>>x;

    list->setSize(x);
    list->setElements();
    std::cout<<"\nMaximum element in the list is: "<<list->findMax();
    std::cout<<"\nMinimum element in the list is: "<<list->findMin();
    list->sort();
    std::cout<<"\nThe sorted list is: ";
    list->display();
    
}