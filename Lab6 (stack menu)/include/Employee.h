
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee
{
private:
    char* name;
    int age;
    double salary;

public:
    Employee();
    Employee(char* name, int age, double salary);

    void SetName(char* name);
    void SetAge(int age);
    void SetSalary(double salary);

    char* GetName();
    int GetAge();
    double GetSalary();
};

std::ostream& operator<<(std::ostream& out, Employee& emp);

#endif
