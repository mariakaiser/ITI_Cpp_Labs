#include <iostream>
#include "../include/LL_Queue.h"

LL_Queue::LL_Queue()
{
    this->head = nullptr;
    this->tail = nullptr;
}

void LL_Queue::enqueue(int data)
{
    Node * node = new Node(data);

    if(this->head == nullptr) // first element
    {
        this->head = node;
        this->tail = node;
        node = nullptr;
    }
    else // insert at tail 
    {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
}

void LL_Queue::dequeue()
{
    if(this->head == nullptr) // empty
    {
        std::cout<<"Queue is already empty"<<std::endl;
        return;
    }
    else if(tail == head) // the only one left
    {
        delete tail;
        tail = head = nullptr;
    }
    else // remove from head
    {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
}

void LL_Queue::display()
{
    Node * current = this->head;
    while (current != nullptr)
    {
        std::cout<<current->data<<"\t";
        current= current->next;
    }
    std::cout<<std::endl;
}