#include <iostream>
#include "../include/Stack.h";

int factorial(int n)
{
    Stack s;
    for(int i = n;i>0;i--)
    {
        s.push(i);
    }

    int a,b;
    while (true)
    {
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();
        if(s.isEmpty())
            return (a*b);
        s.push(a*b);
    }

}

// bubble , selection , BS by linked list