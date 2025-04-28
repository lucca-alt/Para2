#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
class Complex{
private:
    double real, imag;
public:
    Complex();
    Complex(double real, double imag);
    double getReal();
    double getImag();
    Complex add(Complex num1 , Complex num2);
    Complex subtract(Complex num1 , Complex num2);
    Complex multiply(Complex num1 , Complex num2);
    Complex divide(Complex num1 , Complex num2);
    Complex operator+(const Complex &num2);
    Complex operator-(const Complex &num2);
    Complex operator*(const Complex &num2);
    Complex operator/(const Complex &num2);
    Complex operator!();
    friend std::ostream& operator<<(std::ostream &out, const Complex &num1); //friend can access private members
};

#endif /* COMPLEX_H */