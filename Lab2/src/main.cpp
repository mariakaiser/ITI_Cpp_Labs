#include <iostream>
#include "../include/string_functions.h"

int main()
{
    char name[10] = "Maria123";

    // ToUpper(name);

    // std::cout << name <<std::endl;

    // ToLower(name);

    // std::cout << name <<std::endl;

    //std::cout<<StringCompare("Maria123",name);

    char * copied = StringCopy(name);

    std::cout<<copied << std::endl;

    return 0;
}