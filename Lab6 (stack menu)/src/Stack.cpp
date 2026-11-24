#include "../include/Stack.h"

Stack::Stack()
{
    this->sizeArray=10;
    this->top=-1;
    this->items=new Employee[sizeArray];
    //ctor
}
Stack::Stack(Stack & s)
{
    this->items=new Employee[s.sizeArray];
    this->sizeArray=s.sizeArray;
    this->top=s.top;
    for(int i=0; i<=top; i++){
            this->items[i]=s.items[i];
    }
}

int Stack::GetSize()
{
    return this->sizeArray;
}
Stack::Stack(int sizeArray)
{
    this->sizeArray=sizeArray;
    this->top=-1;
    this->items=new Employee[sizeArray];
    //ctor
}
void Stack:: push(Employee data){
   if(top >= sizeArray -1){//5
        return ; //Early Exit
   }
   top++;
   items[top]=data;
}
int Stack::pop(Employee * data){
    if(top == -1){
        return 0;
    }
    *data=items[top];
    top--;
    return 1;
}

void Stack:: display(void){
   for(int i=top; i>=0; i--){
        std::cout<<"Employee "<<i + 1<<std::endl;
        std::cout<<items[i]<<std::endl;
   }
}

Stack::~Stack()
{
    delete []items;
    //dtor
}
