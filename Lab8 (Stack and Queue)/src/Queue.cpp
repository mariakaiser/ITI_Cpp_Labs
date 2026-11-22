#include <iostream>
#include "../include/Queue.h"

Queue::Queue(int size)
{
    this->size = size;
    this->d_array = new int(size);
    this->front = -1;
    this->back = -1;
}

void Queue::enqueue(int data)
{
    if(((back+1)%this->size) == front)
    {
        std::cout<<"Queue is full "<<std::endl;
        return;
    }
    if(front == -1) // first time
    {
        d_array[0] = data;
        front = back = 0;
    }
    else 
    {
        back = (back+1) % this->size;
        d_array[back] = data;
    }
}

void Queue::dequeue()
{
    if(this->front == -1)
    {
        std::cout<<"Queue is already empty "<<std::endl;
        return;
    }
    
    if(this->front+1 > this->back)
    {
        this->back = this->front = -1;
        return;
    }
    front = (front+1) % this->size;
}

void Queue::display()
{
    if(this->front == -1)
        return;
    for(int i = front;i<=back;i++)
    {
        std::cout<<this->d_array[i]<<"\t";
    }
    std::cout<<std::endl;
}