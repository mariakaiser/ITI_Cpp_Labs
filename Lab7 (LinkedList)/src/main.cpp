#include <iostream>
#include "../include/LinkedList.h"

int main()
{
    LinkedList l;
    l.Insert(1);
    l.Insert(2);
    l.Insert(3);

    //l.display();

    // l.InsertAfter(1,10);
    // l.InsertAfter(3,30);
    // l.InsertAfter(5,30);

    // l.display();

    // l.InsertBefore(1,0);
    // l.InsertBefore(3,15);
    
    // l.display();

    //std::cout<<l.GetCount();


    std::cout<<l.GetDataByIndex(0)<<std::endl;
    std::cout<<l.GetDataByIndex(2)<<std::endl;

    std::cout<<l.GetDataByIndex(-1);




}