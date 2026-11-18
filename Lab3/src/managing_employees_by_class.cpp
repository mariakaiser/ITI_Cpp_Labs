#include <iostream>
#include "Employee.cpp"

Employee employees[30]; // calls the default constructor for each
int num_current_employees = 0;
int MaxEmployees = -1;

void SetStaticSize(int size)
{
    MaxEmployees = size;
}

void AddStaticEmployee(char * name, int age, double salary)
{
    if(num_current_employees==MaxEmployees)
    {
        std::cout<<"you reached max number of employees";
        return;
    }
    employees[num_current_employees].SetName(name);
    employees[num_current_employees].SetAge(age);
    employees[num_current_employees].SetSalary(salary);
    num_current_employees++;
}

void DisplayStaticEmployees()
{
    std::cout<<"Number of employees "<<num_current_employees<<std::endl<<std::endl;

    for(int i = 0;i<num_current_employees;i++)
    {
        std::cout<<"Employee "<<i+1<<std::endl;

        std::cout<<"Name : "<<employees[i].GetName()<<std::endl;
        std::cout<<"Age : "<<employees[i].GetAge()<<std::endl;
        std::cout<<"Salary : "<<employees[i].GetSalary()<<std::endl;

        std::cout<<"================================="<<std::endl;
    }
}