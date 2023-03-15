#include <iostream>

class person {
public:
    int a = 0;
    person() = default;
    virtual ~person() { std::cout<<"person destroyed"<<std::endl; }
    void show() { std::cout<<"just a person: "<<a<<std::endl; }
};

class father : virtual public person {
public:
    int a = 1;
    father() = default;
    ~father() { std::cout<<"father destroyed"<<std::endl; }
    void show() { std::cout<<"Characteristics of father: "<<a<<std::endl; }
};

class mother : virtual public person {
public:
    int a = 2;
    mother() = default;
    ~mother() { std::cout<<"mother destroyed"<<std::endl; }
    void show() { std::cout<<"Characteristics of mother: "<<a<<std::endl; }
};

class child : public father, public mother {
public:
    //int a = 3;
    child() = default;
    ~child() { std::cout<<"child destroyed"<<std::endl; }
    void show() {
        father::show();
        mother::show();
        //std::cout<<a<<std::endl;
    }
};


int main()
{
    // child c;
    // c.show();
    // std::cout<<c.person::a;

    father* f = new father();
    person *p = f;

    delete p;

}