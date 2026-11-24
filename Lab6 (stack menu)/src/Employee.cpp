
#include "../include/Employee.h"
#include "../include/string_functions.h"

Employee::Employee()
{
    name = nullptr;
    age = 0;
    salary = 0;
}

Employee::Employee(char* name, int age, double salary)
{
    this->name = StringCopy(name);
    this->age = age;
    this->salary = salary;
}

void Employee::SetName(char* name)
{
    this->name = StringCopy(name);
}

void Employee::SetAge(int age)
{
    this->age = age;
}

void Employee::SetSalary(double salary)
{
    this->salary = salary;
}

char* Employee::GetName()
{
    return name;
}

int Employee::GetAge()
{
    return age;
}

double Employee::GetSalary()
{
    return salary;
}

std::ostream& operator<<(std::ostream& out, Employee& emp)
{
    out << "Name : " << emp.GetName() << std::endl;
    out << "Age : " << emp.GetAge() << std::endl;
    out << "Salary : " << emp.GetSalary() << std::endl;

    return out;
}
