/*
Consider Class complex shown in Figs10.14-10.16.  
The class enables operations on so called complex numbers.  
THese are numbers of the form realPart + imaginaryPart * i,
where i has the value Squareroot(-1)

a-  Modify the class to enable input and output of complex numbers via
overloaded >> and << operators, respectively ( you should remove the
toString function from the class).
b- Overload the mutliplication operator to enable multiplication 
of two complex numbers as in algebra.
c- Overload the == and != operators to allow comparisons of complex 
numbers.


*/

// Fig. 10.15 : Complex.cpp 
// Complex class member-function definitions. 
#include <string>
#include <iostream>

#include "Complex.h" // Complex class definition
using namespace std; 

// Constructor 
Complex::Complex(double realPart, double imaginaryPart) 
: real {realPart}, imaginary {imaginaryPart} { } 

// addition operator  
Complex Complex::operator+ (const Complex& operand2) const { 
    return Complex {real +operand2.real, imaginary+ operand2.imaginary}; 
} 

// subtraction operator 
Complex Complex::operator-(const Complex& operand2) const { 
    return Complex { real - operand2.real, imaginary - operand2.imaginary } ; 
} 

// return string representation of a complex object in the form: (a, b) 
string Complex::toString () const { 
    return "("s +to_string(real) + ", "s + to_string(imaginary) + ")"s; 
}

// multiplication operator
Complex Complex::operator*(const Complex& operand2) const {
    return Complex {real * operand2.real - imaginary * operand2.imaginary, real * operand2.imaginary + imaginary * operand2.real};
}

// equality operator
bool Complex::operator==(const Complex& operand2) const {
    return real == operand2.real && imaginary == operand2.imaginary;
}

// inequality operator
bool Complex::operator!=(const Complex& operand2) const {
    return !(*this == operand2);
}

// Overloaded input operator for class Complex
istream& operator>>(istream& input, Complex& complex) {
    input >> complex.real;
    input >> complex.imaginary;
    return input;
}

// Overloaded output operator for class Complex
ostream& operator<<(ostream& output, const Complex& complex) {
    output << "(" << complex.real << ", " << complex.imaginary << ")";
    return output;
}
// end function operator<<
// end function operator>>


/**
 * The main function is the entry point of the program.
 * It demonstrates the usage of the Complex class by performing various operations on Complex numbers.
 */
int main(){
    Complex y(4.3, 8.2);    
    Complex z(9, 2);
    Complex x;
    cout << "x: " << x.toString() << "\ny: " << y.toString() << "\nz: " << z.toString() << "\n";

    x= y + z;
    cout << "\n\nx = y + z:\n" << x.toString() << " = " << y.toString() << " + " << z.toString() << "\n";

    x= y - z;
    cout << "\n\nx = y - z:\n" << x.toString() << " = " << y.toString() << " - " << z.toString() << "\n";

    x= y * z;
    cout << "\n\nx = y * z:\n" << x.toString() << " = " << y.toString() << " * " << z.toString() << "\n";

    if (y == z) {
        cout << "\n\ny is equal to z\n";
    } else {
        cout << "\n\ny is not equal to z\n";
    }


    if (y != z) {
        cout << "y is not equal to z\n";
    } else {
        cout << "y is equal to z\n";
    }

    return 0;
}