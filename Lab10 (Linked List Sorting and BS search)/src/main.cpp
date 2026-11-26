#include <iostream>
#include "../include/LinkedList.h"
#include "../include/sortring_search.h"

int main()
{
    LinkedList ll;
    ll.Insert(4);
    ll.Insert(3);
    ll.Insert(2);
    ll.Insert(1);

    //BubbleSort(ll);
    SelectionSort(ll);

    ll.display();

    std::cout<<BinarySearch(ll,3);

    return 0;
}