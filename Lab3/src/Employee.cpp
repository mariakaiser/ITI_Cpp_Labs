#include "../include/string_functions.h"

class Employee
{
    private:
        char* name;
        int age;
        double salary;
    public:
    Employee()
    {
        this->name = nullptr;
        this->age = 0;
        this->salary = 0;
    }
    Employee(char * name, int age, double salary)
    {
        this->name = StringCopy(name);
        this->age = age;
        this->salary = salary;
    }
    
    void SetName(char * name)
    {
        this->name = StringCopy(name);
    }
    void SetAge(int age)
    {
        this->age = age;
    }
    void SetSalary(double salary)
    {
        this->salary = salary;
    }

    char* GetName()
    {
        return name;
    }

    int GetAge()
    {
        return age;
    }

    double GetSalary()
    {
        return salary;
    }
};
