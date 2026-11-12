#include <iostream>
#include <string>
#include "../include/helpers.h"
#include "../include/ArrowInput2.h"
#include "../include/managing_employees_by_class.h"
#include "../include/managing_employees_by_struct.h"
#include "../include/string_functions.h"

void BuildMenu(bool choice);

// bool op 0 -> up      1 -> down
// range from 0 to 2    0 -> new      1 -> display        2 -> exit
int ArrowPos(int current_pos, bool op)
{
    if(op)
    {
        current_pos++;
        if(current_pos==3)
            current_pos =0;
    }
    else
    {
        current_pos--;
        if(current_pos == -1)
            current_pos = 2;
    }
    return current_pos;
}

void ResetLine(int option_number)
{
    if(option_number == 0)
    {
        ClearLine(5);
        Write(5, 20, "White", "New");
    }
    else if(option_number == 1)
    {
        ClearLine(10);
        Write(10, 20, "White", "Display");
    }
    else 
    {
        ClearLine(15);
        Write(15, 20, "White", "Exit");
    }
}

void ColorChosenOption(int option_number)
{
    if(option_number == 0)
    {
        ClearLine(5);
        Write(5, 17, "Yellow", "->");
        Write(5, 20, "Yellow", "New");
    }
    else if(option_number == 1)
    {
        ClearLine(10);
        Write(10, 17, "Yellow", "->");
        Write(10, 20, "Yellow", "Display");
    }
    else 
    {
        ClearLine(15);
        Write(15, 17, "Yellow", "->");
        Write(15, 20, "Yellow", "Exit");
    }
}

void GoHome(bool choice)
{
    ClearTerminal();
    BuildMenu(choice);
}

double ValidatePositiveNumber(string message , int row , int col)
{
    double input;
    Write(row, col, "White", message);
    PositionOnScreen(row + 1,col);

    while (!(cin >> input) || (input<0))
    {
        Write(row, col + message.size() +5, "White", "Invalid input try again");
        PositionOnScreen(row +1,col);
        cin.clear(); //Resets the error state of cin.
        cin.ignore(1000, '\n'); //Discards characters from the input buffer.
    }

    //Discards characters from the input buffer if the user entered double it would disrupt the next cin
    cin.ignore(1000, '\n'); 
    ClearLine(row); // remove the error line if happend
    Write(row, col, "White", message);
    
    return input;
}

bool IsValidName(char* name)
{

    int counter = 0;
    while(name[counter] != '\0')
    {
        if(!((name[counter] >= 'a' && name[counter]<= 'z') || name[counter] >= 'A' && name[counter]<= 'Z'))
        {
            return false;
        }
        counter++;
    }

    return true;
}

void StaticNewEmployeePage()
{
    Write(1, 1, "White", "Static");
    
    int num_of_employees =0;
    num_of_employees = ValidatePositiveNumber("Enter number of employees : " , 5, 17);
 
    SetStaticSize(num_of_employees);

    ClearTerminal();

    char name[10];
    int age;
    double salary;

    int counter = 0;
    char ans = 'y';
    bool again =1;
    while(again && (counter != num_of_employees))
    {
        Write(1, 1, "White", "Static");

        Write(5, 17, "White", "Employee " + std::to_string(counter+1));
        PositionOnScreen(6,17);

        // ---- Name Validation --------------------------------------

        bool valid_name = true;

        do
        {
            Write(10, 17, "White", "Employee Name : ");
            PositionOnScreen(11,17);
            std::cin>>name;
            valid_name = IsValidName(name);
            if(!valid_name)
            {
                Write(10, 35, "White", "Invalid Input");
            }

        } while(!valid_name);
        ClearLine(10);
        Write(10, 17, "White", "Employee Name : ");

        // ------------------------------------------------------------

        age = ValidatePositiveNumber("Employee Age : " , 13, 17);

        salary = ValidatePositiveNumber("Employee Salary : " , 16, 17);
      
        AddStaticEmployee(name, age, salary);

        Write(19, 17, "White", "Enter another? y/n");
        PositionOnScreen(20,17);
        std::cin>>ans;
        (ans == 'y')?again = 1 : again = 0;

        ClearTerminal();

        counter++;
    }

    if(again && (counter == num_of_employees))
    {
        Write(5, 17, "White", "You have reached the limit of employees" );
    }

    Write(10, 17, "White", "Press home to go back to menu");
    int operation = DetermineArrow();
    if(operation == 4)
        GoHome(0);

}

void DynamicNewEmployeePage()
{
    Write(1, 1, "White", "Dynamic");

    InitDynamicEmplyeeArr();

    char name[10];
    int age;
    double salary;

    int counter = 0;
    char ans = 'y';
    bool again =1;

    while(again)
    {
        Write(1, 1, "White", "Dynamic");

        Write(5, 17, "White", "Employee " + std::to_string(counter+1));
        PositionOnScreen(6,17);

        // ---- Name Validation --------------------------------------

        bool valid_name = true;

        do
        {
            Write(10, 17, "White", "Employee Name : ");
            PositionOnScreen(11,17);
            std::cin>>name;
            valid_name = IsValidName(name);
            if(!valid_name)
            {
                Write(10, 35, "White", "Invalid Input");
            }

        } while(!valid_name);
        ClearLine(10);
        Write(10, 17, "White", "Employee Name : ");

        // ------------------------------------------------------------

        age = ValidatePositiveNumber("Employee Age : " , 13, 17);

        salary = ValidatePositiveNumber("Employee Salary : " , 16, 17);
        
      
        AddDynamicEmployee(name, age, salary);

        Write(19, 17, "White", "Enter another? y/n");
        PositionOnScreen(20,17);
        std::cin>>ans;
        (ans == 'y')?again = 1 : again = 0;

        ClearTerminal();

        counter++;
    }

    Write(10, 17, "White", "Press home to go back to menu");
    int operation = DetermineArrow();
    if(operation == 4)
        GoHome(1);
}

void NewEmployeePage(bool choice) // can remove it
{
    if(choice)
        DynamicNewEmployeePage();
    else
        StaticNewEmployeePage();
}

void DisplayEmployeesPage(bool choice)
{
    (choice)? Write(1, 1, "White", "Dynamic") : Write(1, 1, "White", "Static");
    std::cout<<endl;
    if (choice) 
            DisplayDynamicEmployees();
        else        
            DisplayStaticEmployees();

    std::cout<<"Press home to go back to menu"<<std::endl;
    int operation = DetermineArrow();
    if(operation == 4)
    {
        GoHome(choice);
    }
}

// static -> 0      dynamic -> 1
void BuildMenu(bool choice)
{
    (choice)? Write(1, 1, "White", "Dynamic") : Write(1, 1, "White", "Static");

    Write(5, 17, "Yellow", "->");
    Write(5, 20, "Yellow", "New");
    Write(10, 20, "White", "Display");
    Write(15, 20, "White", "Exit");

    // 1 -> up arrow
    // 2 -> down arrow
    // 3 -> enter
    // 4 -> home

    int operation = 0;
    int arrow_pos =0;  //  0 -> new      1 -> display        2 -> exit
    while(operation != 3)
    {
        //std::cout<<"enterd while \n";
        operation = DetermineArrow();
        //std::cout<< operation;
        if(operation == 1) // up
        {
            // std::cout<<"enter if";
            ResetLine(arrow_pos);
            arrow_pos = ArrowPos(arrow_pos, 0);
            ColorChosenOption(arrow_pos);
        }
        else if(operation == 2) // down
        {
            ResetLine(arrow_pos);
            arrow_pos = ArrowPos(arrow_pos, 1);
            ColorChosenOption(arrow_pos);
        }
        else if(operation == 4) // home
        {
            ResetLine(arrow_pos);
            arrow_pos = 0;
            ColorChosenOption(arrow_pos);
        }
        else if(operation == 6) // end
        {
            ResetLine(arrow_pos);
            arrow_pos = 2;
            ColorChosenOption(arrow_pos);
        }
    }
    ClearTerminal();
    if(arrow_pos == 0)
    {
        NewEmployeePage(choice);
        //StaticNewEmployeePage();
    }
    else if(arrow_pos == 1)
    {
        DisplayEmployeesPage(choice);
    }
    else if(arrow_pos == 2)
    {
        return;
    }
}

void Start()
{
    char choice;

    do
    {
        std::cout << "Static/Dynamic? (s/d): ";
        std::cin >> choice;

        if (choice != 's' && choice != 'd' && choice != 'S' && choice != 'D')
        {
            std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 's' && choice != 'd' && choice != 'S' && choice != 'D');

    ClearTerminal();

    

    // static -> 0      dynamic -> 1
    ((choice == 's') || (choice == 'S'))? BuildMenu(0) : BuildMenu(1);
}