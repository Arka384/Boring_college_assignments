#include <iostream>

class Pattern {
protected:
    int lines;
public:
    virtual void setLineNumber(int ) = 0;
    virtual void generatePattern(void ) = 0;
};

class InvertPyramid : public Pattern {
public:
    InvertPyramid() {};
    void setLineNumber(int line) {
        this->lines = line;
    }
    void generatePattern() {
        for(int i=0;i<lines;i++) {
            for(int j=0;j<=i;j++)
                std::cout<<" ";
            for(int j=0;j<((lines-1-i)*2+1);j++)
                std::cout<<"*";
            std::cout<<"\n";
        }
    }

};

int main()
{
    int x;
    InvertPyramid* p = new InvertPyramid();
    std::cout<<"\nEnter the number of line: ";
    std::cin>>x;
    p->setLineNumber(x);
    p->generatePattern();
}