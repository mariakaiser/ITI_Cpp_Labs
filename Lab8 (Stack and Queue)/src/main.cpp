#include <iostream>
#include "../include/Stack.h"
#include "../include/LL_Queue.h"
#include "../include/Queue.h"

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    s.display();

    s.pop();
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();

    // LL_Queue q;
    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(3);

    // q.display();

    // q.dequeue();
    // q.display();
    // q.dequeue();
    // q.display();
    // q.dequeue();
    // q.display();
    // q.dequeue();
    // q.display();

    // Queue q2(3);
    // q2.enqueue(1);
    // q2.enqueue(2);
    // q2.enqueue(3);
    // //q2.enqueue(4);

    // q2.display();

    // q2.dequeue();
    // q2.display();
    // q2.dequeue();
    // q2.display();
    // q2.dequeue();
    // q2.display();

    // q2.dequeue();

  
   






    return 0;
}