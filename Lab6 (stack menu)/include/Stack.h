#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "../include/Employee.h"

class Stack
{

    public:
        Stack();
        Stack(int sizeArray);
        ~Stack();
        int GetSize();
        Stack(Stack & s);
        void push(Employee data);
        int pop(Employee * data);
        void display(void);
    protected:

    private:
        int top;
        int sizeArray;
        Employee *items;
};

#endif // STACK_H
