#include <iostream>
#include "../include/Complex.h"

using namespace std;

Complex::Complex()
{
    this->real =0;
    this->img = 0;
}

Complex::Complex(double real, double img)
{
    this->real = real;
    this->img = img;
}

int Complex::getReal()const
{
    return real;
}

int Complex::getImg()const
{
    return img;
}

void Complex::setReal(double real)
{
    this->real = real;
}

void Complex::setImg(double img)
{
    this->img = img;
}

void Complex::getComplex() const
{
    if(real !=0){
        cout<<real;
    }
    if(img !=0 ){
        (img >0)?cout<<"+"<<img<<"j"<<endl:cout<<img<<"j"<<endl;
    }
}
// addition overloading
Complex Complex:: operator+ (const Complex & other) const // C1 + C2
{
    return Complex(this->real+other.real,this->img+other.img);
}

Complex Complex:: operator+ (int x) const // C1 + 3
{
    return Complex(this->real+ x,this->img);
}
// subtraction overloading
Complex Complex:: operator- (const Complex & other) const // C1 - C2
{
    return Complex(this->real-other.real,this->img-other.img);
}

Complex Complex:: operator- (int x) const // C1 - 3
{
    return Complex(this->real- x,this->img);
}

// multiplication overloading
Complex Complex::operator* (const Complex &other) const
{
    return Complex(this->real * other.real, this->img * other.img);
}

Complex Complex::operator* (const int x) const
{
    return Complex(this->real * x, this->img);
}

// division overloading
Complex Complex::operator/ (const Complex &other) const // c1/c2
{
    return Complex(this->real / other.real, this->img / other.img);
}

Complex Complex::operator/ (const int x) const // c/3
{
    return Complex(this->real / x, this->img);
}

// Destructor
Complex::~Complex()
{
}

// standalones , uses get so it does not have to be a friend
Complex operator+ (int x,const Complex & c) // 3 + c
{
    return Complex(c.getReal()+x,c.getImg());
}

// standalone but is a friend so it can access private fields
Complex operator- (int x,const Complex & c) // 3 - c
{
    return Complex(x-c.real,c.img);
}
Complex operator* (int x,const Complex & c) // 3 * c
{
    return Complex(c.real*x,c.img);
}

Complex operator/ (int x,const Complex & c) // 3 / c
{
    return Complex(x/c.real,c.img);
}

// ++ overloading
Complex Complex::operator++ () // prefix
{
    return Complex(this->real++, this->img++);
}

Complex Complex::operator++ (int x) // postfix
{
    Complex old(this->real,this->img);
    this->real++;
    this->img++;
    return old;
}

// << overloading
ostream& operator<< (ostream& out,const Complex &other)
{
    out << other.getReal() <<" "<< other.getImg();
    return out;
}

// >> overloading 
void operator>> (std::istream& in,Complex &other)
{
    double r, i;
    in>>r>>i;
    other.setReal(r);
    other.setImg(i);
}