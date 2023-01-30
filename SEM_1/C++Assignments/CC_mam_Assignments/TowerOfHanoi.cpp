#include "DescendingStack.hpp"

void towerOfHanoi(int , DescendingStack& , DescendingStack& , DescendingStack& );

int main()
{
    int numberOfDisks;
    int temp;
    CustomStack s;

    std::cout<<"\nEnter number of disks: ";
    std::cin>>numberOfDisks;
    std::cout<<"\nEnter the size of disks: ";
    for(int i=1;i<=numberOfDisks;i++) {
        std::cin>>temp;
        s.push(temp);
    }

    DescendingStack from_rod(s), to_rod, aux_rod;

    towerOfHanoi(numberOfDisks, from_rod, to_rod, aux_rod);
    
}

void towerOfHanoi(int n, DescendingStack& from_rod, DescendingStack& to_rod, DescendingStack& aux_rod)
{
    if (n == 0)
        return;

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    int currentDisk = from_rod.pop();
    to_rod.push(currentDisk);

    std::cout<<"\nSource: ";
    from_rod.display();
    std::cout<<"\nDest: ";
    to_rod.display();
    std::cout<<"\nHelper: ";
    aux_rod.display();
    std::cout<<"\n";

    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
    
}