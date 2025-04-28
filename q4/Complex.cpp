#include "Complex.h"
#include <iostream>

Complex::Complex() : real(0), imag(0){} //default constructor

Complex::Complex(double real, double imag) 
    : real(real), imag(imag){} //argument constructor

double Complex::getReal(){
    return this->real;
}

double Complex::getImag(){
    return this->imag;
}

Complex Complex::add(Complex num1, Complex num2){
    Complex resultAdd;

    resultAdd.real = num1.real + num2.real;
    resultAdd.imag = num1.imag + num2.imag;

    return resultAdd;
}

Complex Complex::subtract(Complex num1, Complex num2){
    Complex resultSub;

    resultSub.real = num1.real - num2.real;
    resultSub.imag = num1.imag - num2.imag;

    return resultSub;
}

Complex Complex::multiply(Complex num1, Complex num2){
    Complex resultMul;

    resultMul.real = num1.real * num2.real - num1.imag * num2.imag; //formula I found online
    resultMul.imag = num1.real * num2.imag + num1.imag * num2.real;

    return resultMul;
}

Complex Complex::divide(Complex num1, Complex num2){
    Complex resultDiv;

    double denominator = num2.real * num2.real + num2.imag * num2.imag;
    resultDiv.real = (num1.real * num2.real + num1.imag * num2.imag) / denominator; //formula I found online
    resultDiv.imag = (num1.imag * num2.real - num1.real * num2.imag) / denominator;

    return resultDiv;
}

Complex Complex::operator+(const Complex &num2){
    Complex resultAddOP;

    resultAddOP.real = this->real + num2.real;
    resultAddOP.imag = this->imag + num2.imag;

    return resultAddOP;
}

Complex Complex::operator-(const Complex &num2){
    Complex resultSubOP;

    resultSubOP.real = this->real - num2.real;
    resultSubOP.imag = this->imag - num2.imag;

    return resultSubOP;
}

Complex Complex::operator*(const Complex &num2){
    Complex resultMulOP;

    resultMulOP.real = this->real * num2.real - this->imag * num2.imag; 
    resultMulOP.imag = this->real * num2.imag + this->imag * num2.real;

    return resultMulOP;
}

Complex Complex::operator/(const Complex &num2){
    Complex resultDivOP;

    double denominatorOP = num2.real * num2.real + num2.imag * num2.imag;
    resultDivOP.real = (this->real * num2.real + this->imag * num2.imag) / denominatorOP; 
    resultDivOP.imag = (this->imag * num2.real - this->real * num2.imag) / denominatorOP;

    return resultDivOP;
}

Complex Complex::operator!(){ //conjugation operator overloading
    Complex conjugate;

    conjugate.real = this->real;
    conjugate.imag = -this->imag;

    return conjugate;
}

std::ostream& operator<<(std::ostream &out, const Complex &num1){
    out << num1.real << " + " << num1.imag << "i" << std::endl; //makes it possible to print complex numbers

    return out;
}