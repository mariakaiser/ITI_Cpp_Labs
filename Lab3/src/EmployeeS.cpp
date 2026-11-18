#include "../include/string_functions.h"


struct S_Employee
{
    private:
    char* name;
    int age;
    double salary;

    public:
    S_Employee()
    {
        this->name = nullptr;
        this->age = 0;
        this->salary = 0;
    }

    S_Employee(char * name, int age, double salary)
    {
        this->name = StringCopy(name);
        this->age = age;
        this->salary = salary;
    }

       
    void SetName(char * name)
    {
        char* newName = StringCopy(name);
        delete[] this->name;
        this->name = newName;
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

    S_Employee& operator=(const S_Employee& other)
    {
     
        char* newName = StringCopy(other.name);

        delete[] name;

        name = newName;
        age = other.age;
        salary = other.salary;
        
        return *this;
    }

    ~S_Employee()
    {
        delete[] name;
    }
};
