#include <iostream>

class Complex
{

private:
    double real ;
    double img;

public:
    Complex();
    Complex(double real, double img);
    int getReal()const;
    int getImg()const;
    void setReal(double real);
    void setImg(double img);
    void getComplex() const;
    // + overloading
    Complex operator+ (const Complex & other) const;
    Complex operator+ (int x) const ;
    // - overloading
    Complex operator- (const Complex & other) const;
    Complex operator- (int x) const ;
    friend Complex operator- (int x,const Complex & c); 
    // * overloading
    Complex operator* (const Complex &other) const;
    Complex operator* (const int x) const;
    friend Complex operator* (int x,const Complex & c); 
    // / overloading
    Complex operator/ (const Complex &other) const;
    Complex operator/ (const int x) const;
    friend Complex operator/ (int x,const Complex & c); 
    // ++ overloading
    Complex operator++ ();
    Complex operator++ (int);
   


    ~Complex();
};

// standalone
Complex operator+ (int x,const Complex & c); // not a friend its oustide the class

 // <<
std::ostream& operator<< (std::ostream& out,const Complex &other); // cout << c

// >>
void operator>> (std::istream& in, Complex &other); // cin >> c


