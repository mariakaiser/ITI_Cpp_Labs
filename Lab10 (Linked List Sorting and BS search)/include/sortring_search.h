#include "../include/LinkedList.h"

void Swap(int &a,int &b);
void BubbleSort(LinkedList &l);    // O(n^2)
void SelectionSort(LinkedList &l); // O(n^3)
int BinarySearch(LinkedList &l , int target); // O(n)
int BS(int start,int end, LinkedList l , int target); // helper
