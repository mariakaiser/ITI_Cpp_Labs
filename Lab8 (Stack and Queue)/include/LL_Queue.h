#include "../include/Node.h"

class LL_Queue
{
private:
    Node * head;
    Node * tail;
public:
    LL_Queue();
    void display();
    void enqueue(int data);
    void dequeue();
};
