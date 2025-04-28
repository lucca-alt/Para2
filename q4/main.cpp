#include "Complex.h"
#include <iostream>

using namespace std;

int main(){
    Complex num1(2.0, 4.0);
    Complex num2(6.0, 2.0);
    Complex num3(1.0, -3.0);
    Complex num4(3.0, -5.0);
    Complex x(5.0, 9.0);
    Complex y(8.0, 2.0);

    Complex numerator = num2.add(num2, num3);
    Complex fraction = numerator.divide(numerator, num4);
    Complex result = num1.subtract(num1, fraction);

    cout << result.getReal() << " + " << result.getImag() << "i" << endl << endl;

    cout << "Testing Operator Overloading:" << endl;
    cout << "______________________________" << endl;
    cout << "Addition:        x + y = " << x + y << endl;
    cout << "Subtraction:     x - y = " << x - y << endl << endl;
    cout << "Multiplication:  x * y = " << x * y << endl;
    cout << "Division:        x / y = " << x / y << endl;
    cout << "Conjugation:     x = " << x << " and x! = " << !x << endl;
    return 0;
}