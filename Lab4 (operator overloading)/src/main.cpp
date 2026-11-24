#include <iostream>
#include "../include/Complex.h"

int main()
{
    Complex c(1,-2);
    Complex c2(2,5);

    std::cout<< "c = ";
    c.getComplex();
    std::cout<< "c2 = ";
    c2.getComplex();

    std::cout<<"==========Addition overloading======"<<std::endl;

    std::cout<< "c + c = ";
    Complex res1 = c + c; // copy initialization, not assignment
    res1.getComplex();

    std::cout<< "c + 3 = ";
    Complex res2 = c + 3;
    res2.getComplex();

    std::cout<< "3 + c = ";
    Complex res3 = 3 + c;
    res3.getComplex();

    std::cout<<"==========Subtraction overloading======"<<std::endl;

    std::cout<< "c - c2 = ";
    Complex res10 = c - c2; // copy initialization, not assignment
    res10.getComplex();

    std::cout<< "c - 3 = ";
    Complex res11 = c - 3;
    res11.getComplex();

    std::cout<< "3 - c = ";
    Complex res12 = 3 - c;
    res12.getComplex();

    std::cout<<"==========Multiplication overloading======"<<std::endl;

    std::cout<< "c * c = ";
    Complex res4 = c * c; // copy initialization, not assignment
    res4.getComplex();

    std::cout<< "c * 3 = ";
    Complex res5 = c * 3;
    res5.getComplex();

    std::cout<< "3 * c = ";
    Complex res6 = 3 * c;
    res6.getComplex();

    std::cout<<"==========Division overloading======"<<std::endl;

    std::cout<< "c / c = ";
    Complex res7 = c / c; // copy initialization, not assignment
    res7.getComplex();

    std::cout<< "c / 3 = ";
    Complex res8 = c / 3;
    res8.getComplex();

    std::cout<< "3 / c = ";
    Complex res9 = 3 / c;
    res9.getComplex();

    // in/ out stream

    // c = c2; // valid unless i have dynamic alloc
    //c.getComplex();

    // << overloading
    std::cout<<"========== << overloading======"<<std::endl;
    std::cout<< "c2 = " << c2 << " c = " <<c << std::endl;

    std::cout<<"========== >> overloading======"<<std::endl;
    // >> overloading
    Complex c3;
    std::cin>>c3;
    std::cout<< c3 << std::endl;

    std::cout<<"========== ++ overloading======"<<std::endl; // fe 3'alta
    std::cout<<"Postfix ++ : ";
    std::cout<<c3++<<std::endl;
    std::cout<<"c3 = "<<c3<<std::endl;
    
    std::cout<<"Prefix ++ : ";
    std::cout<<(++c3)<<std::endl;
    std::cout<<"c3 = "<<c3<<std::endl;
    




    return 0;
}

