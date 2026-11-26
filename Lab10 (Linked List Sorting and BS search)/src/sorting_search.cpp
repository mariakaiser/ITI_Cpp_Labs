#include "../include/LinkedList.h"

void Swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b=temp;
}

void BubbleSort(LinkedList &l) // O(n^2)
{
    int LL_size = l.GetCount();
    Node* first_node = l.head;
    Node* second_node = l.head->next;
    bool flag = true;

    for(int i = 0; (i<LL_size -1) && flag;i++)
    {
        flag = false;
        first_node = l.head;
        second_node = l.head->next;
        for(int j = 0;(j<LL_size -1 - i) && first_node && second_node;j++)
        {
            if (first_node->data > second_node->data)
            {
                    Swap(first_node->data,second_node->data);
                    flag = true;
            }
        first_node = first_node->next;
        second_node = second_node->next;
        }
    }
  
}

void SelectionSort(LinkedList &l)  // O(n^3)
{
    int LL_size = l.GetCount();

    int min_index = 0;

    for(int i = 0;i<LL_size;i++)
    {
        min_index = i;
        for(int j = i;j<LL_size;j++)
        {
            if(l.GetDataByIndex(j) < l.GetDataByIndex(min_index))
            {
                min_index = j;
            }
        }
        Swap(l.GetPtrToIndex(min_index)->data,l.GetPtrToIndex(i)->data);
    }
}

int BS(int start,int end, LinkedList l , int target)
{
    int mid_index = start + ((end-start)/2);
    int data_at_mid = l.GetDataByIndex(mid_index); // O(n)

    if(data_at_mid == target)
        return mid_index;

    if(start > end)
        return -1;
    
    if(data_at_mid > target)
    {
        start = mid_index +1;
        return BS(start,end,l,target);
    }

    if(data_at_mid < target)
    {
        end = mid_index - 1;
        return BS(start,end,l,target);
    }
    return -1;
}

int BinarySearch(LinkedList &l , int target) // O(n) -> more than norml O(log n) of using array
{
    int size = l.GetCount();
    return BS(0,size,l,target);
}