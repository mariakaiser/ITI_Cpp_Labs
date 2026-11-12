#include <iostream>
#include "EmployeeS.cpp"

S_Employee* S_employees = NULL;
int S_MaxEmployees = 2;
int S_num_current_employees = 0;


void InitDynamicEmplyeeArr()
{
    S_employees = new S_Employee[S_MaxEmployees]; // creates size Employee struct each called by the default constructor
}

void CopyingInBiggerArr()
{
    
    S_Employee* S_employees_Copy = new S_Employee[S_MaxEmployees*2];

    for(int i =0;i<S_MaxEmployees;i++)
    {
        S_employees_Copy[i] = S_employees[i];
    }

    delete[] S_employees;

    S_employees = S_employees_Copy;

    S_MaxEmployees*=2;
}

void AddDynamicEmployee(char * name, int age, double salary)
{
    if(S_num_current_employees==S_MaxEmployees)
    {
        std::cout<<"Increasing max size";
        CopyingInBiggerArr();
    }
    S_employees[S_num_current_employees].SetName(name);
    S_employees[S_num_current_employees].SetAge(age);
    S_employees[S_num_current_employees].SetSalary(salary);
    S_num_current_employees++;
}

void DisplayDynamicEmployees()
{
    std::cout<<"Number of employees "<<S_num_current_employees<<std::endl;
    
    for(int i = 0;i<S_num_current_employees;i++)
    {
        std::cout<<"Employee "<<i+1<<std::endl;

        std::cout<<"Name : "<<S_employees[i].GetName()<<std::endl;
        std::cout<<"Age : "<<S_employees[i].GetAge()<<std::endl;
        std::cout<<"Salary : "<<S_employees[i].GetSalary()<<std::endl;

        std::cout<<"================================="<<std::endl;
    }
}