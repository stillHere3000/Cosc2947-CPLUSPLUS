/* 
 * File:   main.cpp
*/

#include <iostream>
#include "Rational.h"

using namespace std;



/**
 * The main function is the entry point of the program.
 * It demonstrates the usage of the Rational class by performing arithmetic operations on rational numbers.
 */
int main() {
    cout << "\nHere\n" << endl;
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational r3;

    r3 = r1.add(r2);
    cout << "Adding two rational numbers " << r1.toRationalString(1, 2) << " and " << r2.toRationalString(1, 3) << " equals ";
    r3.display();
    cout << " = ";
    cout << r3.toDouble() << endl;
    

    cout << "Subtracting two rational numbers " << r1.toRationalString(1, 2) << " and " << r2.toRationalString(1, 3) << " equals ";
    r3 = r1.subtract(r2);
    r3.display();
    cout << " = ";
    cout << r3.toDouble() << endl;

    cout << "Multiply two rational numbers " << r1.toRationalString(1, 2) << " and " << r2.toRationalString(1, 3) << " equals ";
    r3 = r1.multiply(r2);
    r3.display();
    cout << " = ";
    cout << r3.toDouble() << endl;

    cout << "Divide two rational numbers " << r1.toRationalString(1, 2) << " and " << r2.toRationalString(1, 3) << " equals ";
    r3 = r1.divide(r2);
    r3.display();
    cout << " = ";
    cout << r3.toDouble() << endl;

    return 0;
}

/**
 * @brief Constructs a Rational object with the given numerator and denominator.
 * 
 * @param n The numerator of the rational number.
 * @param d The denominator of the rational number.
 */
Rational::Rational(int n, int d) {
    numerator = n;
    denominator = d;
    reduce();
}

/**
 * @brief Adds a Rational number to the current Rational number.
 * 
 * This function takes a Rational number as a parameter and adds it to the current Rational number.
 * It returns a new Rational number that represents the sum of the two Rational numbers.
 * 
 * @param r The Rational number to be added.
 * @return The sum of the current Rational number and the parameter Rational number.
 */
Rational Rational::add(const Rational &r) const {
    Rational temp;
    temp.numerator = numerator * r.denominator + denominator * r.numerator;
    temp.denominator = denominator * r.denominator;
    temp.reduce();
    return temp;
}

/**
 * @brief Subtracts a Rational number from the current Rational number.
 * 
 * This function subtracts the given Rational number from the current Rational number
 * and returns the result as a new Rational number.
 * 
 * @param r The Rational number to subtract.
 * @return The result of the subtraction as a new Rational number.
 */
Rational Rational::subtract(const Rational &r) const {
    Rational temp;
    temp.numerator = numerator * r.denominator - denominator * r.numerator;
    temp.denominator = denominator * r.denominator;
    temp.reduce();
    return temp;
}

/**
 * @brief Multiplies the current Rational object with another Rational object.
 * 
 * @param r The Rational object to multiply with.
 * @return The result of the multiplication as a new Rational object.
 */
Rational Rational::multiply(const Rational &r) const {
    Rational temp;
    temp.numerator = numerator * r.numerator;
    temp.denominator = denominator * r.denominator;
    temp.reduce();
    return temp;
}

/**
 * @brief Divides the current Rational object by another Rational object.
 * 
 * @param r The Rational object to divide by.
 * @return The result of the division as a new Rational object.
 */
Rational Rational::divide(const Rational &r) const {
    Rational temp;
    temp.numerator = numerator * r.denominator;
    temp.denominator = denominator * r.numerator;
    temp.reduce();
    return temp;
}

/**
 * Displays the rational number in the form of numerator/denominator.
 */
void Rational::display() const {
    cout << numerator << '/' << denominator;
}

/**
 * Converts the rational number to a double.
 * 
 * @return The rational number as a double.
 */
double Rational::toDouble() const {
    return static_cast<double>(numerator) / denominator;
}

/**
 * Reduces the rational number to its simplest form by dividing both the numerator and denominator by their greatest common divisor.
 */
void Rational::reduce() {
    int sign = 1;
    if (numerator < 0) {
        sign = -1;
        numerator = -numerator;
    }
    if (denominator < 0) {
        sign *= -1;
        denominator = -denominator;
    }
    int common = gcd(numerator, denominator);
    numerator = sign * (numerator / common);
    denominator = denominator / common;
}

/**
 * Calculates the greatest common divisor (GCD) of two numbers.
 * 
 * @param num1 The first number.
 * @param num2 The second number.
 * @return The GCD of num1 and num2.
 */
int Rational::gcd(int num1, int num2) {
    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

/**
 * Converts the rational number to a string representation.
 * 
 * @param num The numerator of the rational number.
 * @param denum The denominator of the rational number.
 * @return The string representation of the rational number in the format "numerator/denominator".
 */
std::string Rational::toRationalString(int num, int denum) const {
    return to_string(numerator) + "/" + to_string(denominator);
}

