#include <iostream>
#include "../include/LinkedList.h"
// #include "../include/Node.h"

LinkedList::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

Node * LinkedList::FindData(int data)
{
    // find data
    Node * current = this->head;
    while(current != nullptr)
    {
        if(current->data == data)
            return current;
        current = current->next;
    }
    return nullptr;
}

void LinkedList::InsertAfter(int data, int afterData)
{
    Node * DataPtr = FindData(data);
   
    if(DataPtr == nullptr)
    {
        std::cout<<"data not found "<<std::endl;
        return;
    }

    Node * OldAfterDataPtr = DataPtr->next;

    // data is found
    Node* AfterDataNode = new Node(afterData);

    if(DataPtr->next == nullptr) // last node
    {
        DataPtr->next = AfterDataNode;
        AfterDataNode->prev = DataPtr;
        this->tail = AfterDataNode;
    }
    else // first or middle
    {
        DataPtr->next = AfterDataNode;
        AfterDataNode->next = OldAfterDataPtr;
        OldAfterDataPtr->prev = AfterDataNode;
        AfterDataNode->prev = DataPtr;
    }
   
}

void LinkedList::InsertBefore(int data, int beforeData)
{
    Node * DataPtr = FindData(data);

    if(DataPtr == nullptr)
    {
        std::cout<<"data not found "<<std::endl;
        return;
    }

    Node * OldBeforeDataPtr = DataPtr->prev;

    // data is found
    Node* BeforeDataNode = new Node(beforeData);

    // its the first in the list
    if(DataPtr == head)
    {
        BeforeDataNode->next= DataPtr;
        DataPtr->prev = BeforeDataNode;
        head = BeforeDataNode;
    }
    else // last or middle
    {
        OldBeforeDataPtr->next = BeforeDataNode;
        BeforeDataNode->next = DataPtr;
        DataPtr->prev = BeforeDataNode;
        BeforeDataNode->prev = OldBeforeDataPtr;
    }

}

int LinkedList::GetCount()
{
    Node * current = this->head;
    int counter = 0;
    while (current != nullptr)
    {
        counter++;
        current = current->next;
    }
    return counter;
}

int LinkedList::GetDataByIndex(int index)
{
    if(index<0)
    {
        std::cout<<"index out of bounds " <<std::endl;
        return -1; // mesh as7 7aga better to throw an exception
    }
    Node * current = this->head;
    for(int i =0;i<index;i++)
    {
        if(current->next == nullptr)
        {
            std::cout<<"index out of bounds " <<std::endl;
            return -1; // mesh as7 7aga better to throw an exception
        }
        current = current->next;
    }

    return current->data;
}

void LinkedList::Insert(int data)
{
    Node * current = this->head;

    Node* node = new Node(data);

    if(current == nullptr) // first node
    {
        head = node;
        tail = node;
    }
    else 
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

void LinkedList::display()
{
    Node * current = this->head;
    while (current != nullptr)
    {
        std::cout<<current->data<<"\t";
        current= current->next;
    }
    std::cout<<std::endl;
}

Node* LinkedList::GetPtrToIndex(int index)
{
    Node* current = this->head;
    for(int i = 0;i<index;i++)
    {
        current = current->next;
    }
    return current;
}
