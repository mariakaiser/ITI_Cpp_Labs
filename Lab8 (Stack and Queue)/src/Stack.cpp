#include <iostream>
#include "../include/Stack.h"

Stack::Stack()
{
    this->head = nullptr;
    this->tail = nullptr;
}

void Stack::push(int data)
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

void Stack::pop()
{
    if(this->head == nullptr) // empty
    {
        std::cout<<"Stack is already empty"<<std::endl;
        return;
    }
    else if(tail == head) // the only one left
    {
        delete tail;
        tail = head = nullptr;
    }
    else 
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
}

int Stack::top()
{
    return tail->data;
}

void Stack::display()
{
    Node * current = this->head;
    while (current != nullptr)
    {
        std::cout<<current->data<<"\t";
        current= current->next;
    }
    std::cout<<std::endl;
}