/*
Create a RationalNumber(functions) class like the one in the previous exercise. 
Provide the following capabilities:
a- Create a constructor that prevents a 0 denominator in a fraction, 
reduces or simplifies fractions that are not in reduced form and avoids negative denominators.
b- Overload the addition, subtraction, multiplication and division operators for this class.
c- Overload the relational and equality operators for this class.
*/

#include <iostream>
#include <string>
#include <cmath>
#include "RationalNumber.h"

using namespace std;

/**
 * @brief Constructs a RationalNumber object with the given numerator and denominator.
 * 
 * @param num The numerator of the rational number.
 * @param den The denominator of the rational number.
 * @throws std::invalid_argument if the denominator is zero.
 */
RationalNumber::RationalNumber(int num, int den) {
    if (den == 0) {
        throw invalid_argument("Denominator cannot be zero");
    }
    if (den < 0) {
        num = -num;
        den = -den;
    }
    numerator = num;
    denominator = den;
    reduce();
}

/**
 * Sets the numerator of the rational number.
 * 
 * @param num The new value for the numerator.
 */
void RationalNumber::setNumerator(int num) {
    numerator = num;
    reduce();
}

/**
 * Sets the denominator of the rational number.
 * 
 * @param den The new denominator value.
 * @throws std::invalid_argument if the denominator is zero.
 */
void RationalNumber::setDenominator(int den) {
    if (den == 0) {
        throw invalid_argument("Denominator cannot be zero");
    }
    if (den < 0) {
        numerator = -numerator;
        den = -den;
    }
    denominator = den;
    reduce();
}

/**
 * @brief Gets the numerator of the rational number.
 * 
 * @return The numerator of the rational number.
 */
int RationalNumber::getNumerator() const {
    return numerator;
}

/**
 * Returns the denominator of the rational number.
 *
 * @return The denominator of the rational number.
 */
int RationalNumber::getDenominator() const {
    return denominator;
}

/**
 * Displays the rational number in the format numerator/denominator.
 */
void RationalNumber::display() const {
    cout << numerator << "/" << denominator;
}

/**
 * @class RationalNumber
 * Represents a rational number with a numerator and denominator.
 */
RationalNumber RationalNumber::operator+(const RationalNumber& r) const {
    int num = numerator * r.denominator + denominator * r.numerator;
    int den = denominator * r.denominator;
    return RationalNumber(num, den);
}

/**
 * @brief Overloaded subtraction operator for RationalNumber objects.
 * 
 * This operator subtracts the given RationalNumber object from the current RationalNumber object.
 * 
 * @param r The RationalNumber object to be subtracted.
 * @return The result of the subtraction as a new RationalNumber object.
 */
RationalNumber RationalNumber::operator-(const RationalNumber& r) const {
    int num = numerator * r.denominator - denominator * r.numerator;
    int den = denominator * r.denominator;
    return RationalNumber(num, den);
}

/**
 * Multiplies two RationalNumber objects.
 *
 * @param r The RationalNumber object to multiply with.
 * @return A new RationalNumber object representing the result of the multiplication.
 */
RationalNumber RationalNumber::operator*(const RationalNumber& r) const {
    int num = numerator * r.numerator;
    int den = denominator * r.denominator;
    return RationalNumber(num, den);
}

/**
 * @class RationalNumber
 * Represents a rational number with a numerator and a denominator.
 */
RationalNumber RationalNumber::operator/(const RationalNumber& r) const {
    if (r.numerator == 0) {
        throw invalid_argument("Cannot divide by zero");
    }
    int num = numerator * r.denominator;
    int den = denominator * r.numerator;
    return RationalNumber(num, den);
}

/**
 * @brief Overloaded equality operator for RationalNumber class.
 * 
 * This operator compares two RationalNumber objects for equality.
 * Two RationalNumber objects are considered equal if their numerators and denominators are equal.
 * 
 * @param r The RationalNumber object to compare with.
 * @return True if the two RationalNumber objects are equal, false otherwise.
 */
bool RationalNumber::operator==(const RationalNumber& r) const {
    return numerator == r.numerator && denominator == r.denominator;
}

/**
 * @brief Overloaded inequality operator for RationalNumber class.
 * 
 * This operator compares two RationalNumber objects for inequality.
 * It returns true if the calling object is not equal to the parameter object,
 * and false otherwise.
 * 
 * @param r The RationalNumber object to compare with.
 * @return true if the calling object is not equal to the parameter object, false otherwise.
 */
bool RationalNumber::operator!=(const RationalNumber& r) const {
    return !(*this == r);
}

/**
 * @brief Overloaded less than operator for RationalNumber class.
 * 
 * This operator compares two RationalNumber objects and returns true if the calling object is less than the parameter object.
 * The comparison is done by multiplying the numerator of the calling object with the denominator of the parameter object,
 * and comparing it with the product of the denominator of the calling object and the numerator of the parameter object.
 * 
 * @param r The RationalNumber object to compare with.
 * @return true if the calling object is less than the parameter object, false otherwise.
 */
bool RationalNumber::operator<(const RationalNumber& r) const {
    return numerator * r.denominator < denominator * r.numerator;
}

/**
 * @brief Overloaded greater than operator for RationalNumber class.
 * 
 * This operator compares two RationalNumber objects and returns true if the calling object is greater than the parameter object.
 * 
 * @param r The RationalNumber object to compare with.
 * @return True if the calling object is greater than the parameter object, false otherwise.
 */
bool RationalNumber::operator>(const RationalNumber& r) const {
    return numerator * r.denominator > denominator * r.numerator;
}

/**
 * Checks if the current RationalNumber is less than or equal to the given RationalNumber.
 *
 * @param r The RationalNumber to compare with.
 * @return True if the current RationalNumber is less than or equal to the given RationalNumber, false otherwise.
 */
bool RationalNumber::operator<=(const RationalNumber& r) const {
    return numerator * r.denominator <= denominator * r.numerator;
}

/**
 * @brief Overloaded greater than or equal to operator for RationalNumber objects.
 * 
 * This operator compares the current RationalNumber object with another RationalNumber object.
 * It returns true if the current object is greater than or equal to the other object, and false otherwise.
 * 
 * @param r The RationalNumber object to compare with.
 * @return true if the current object is greater than or equal to the other object, false otherwise.
 */
bool RationalNumber::operator>=(const RationalNumber& r) const {
    return numerator * r.denominator >= denominator * r.numerator;
}

/**
 * Reduces the rational number to its simplest form by dividing both the numerator and denominator by their greatest common divisor.
 */
void RationalNumber::reduce() {
    int greatestCommonDivisor = gcd(numerator, denominator);
    numerator /= greatestCommonDivisor;
    denominator /= greatestCommonDivisor;
}

/**
 * Calculates the greatest common divisor (GCD) of two numbers.
 * 
 * @param num1 The first number.
 * @param num2 The second number.
 * @return The GCD of num1 and num2.
 */
int RationalNumber::gcd(int num1, int num2) {
    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

/**
 * The main function is the entry point of the program.
 * It creates several RationalNumber objects, performs arithmetic operations on them,
 * and compares them using relational operators.
 * The results are displayed on the console.
 * 
 * @return 0 indicating successful execution of the program.
 */
int main(){
    RationalNumber r1(42, 84);
    RationalNumber r2(31, 62);
    RationalNumber r3(1, 2);
    RationalNumber r4(2, 3);
    RationalNumber r5(3, 4);

    cout << "r1: ";
    r1.display();
    cout << "\nr2: ";
    r2.display();
    cout << "\nr3: ";
    r3.display();
    cout << "\nr4: ";
    r4.display();
    cout << "\nr5: ";
    r5.display();
    cout << "\n";

    RationalNumber r6 = r1 + r2;
    cout << "r6 = r1 + r2: ";
    r6.display();

    r6 = r1 - r2;
    cout << "\nr6 = r1 - r2: ";

    r6.display();

    r6 = r1 * r2;
    cout << "\nr6 = r1 * r2: ";
    r6.display();

    r6 = r1 / r2;
    cout << "\nr6 = r1 / r2: ";
    r6.display();

    if (r1 == r2) {
        cout << "\nr1 is equal to r2";
    } else {
        cout << "\nr1 is not equal to r2";
    }

    if (r1 != r2) {
        cout << "\nr1 is not equal to r2";
    } else {
        cout << "\nr1 is equal to r2";
    }

    if (r3 < r4) {
        cout << "\nr3 is less than r4";
    } else {
        cout << "\nr3 is not less than r4";
    }

    if (r3 > r4) {
        cout << "\nr3 is greater than r4";
    } else {
        cout << "\nr3 is not greater than r4";
    }

    if (r3 <= r4) {
        cout << "\nr3 is less than or equal to r4";
    } else {
        cout << "\nr3 is not less than or equal to r4";
    }

    if (r3 >= r4) {
        cout << "\nr3 is greater than or equal to r4";
    } else {
        cout << "\nr3 is not greater than or equal to r4";
    }
    cout << "\n";
    return 0;

    

}