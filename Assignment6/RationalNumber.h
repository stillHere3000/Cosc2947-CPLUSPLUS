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

using namespace std;

#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

/**
 * @class RationalNumber
 * Represents a rational number with a numerator and a denominator.
 */
class RationalNumber {
    public:
        /**
         * Constructs a RationalNumber object with the given numerator and denominator.
         * @param numerator The numerator of the rational number.
         * @param denominator The denominator of the rational number.
         */
        RationalNumber(int numerator, int denominator);

        /**
         * Sets the numerator of the rational number.
         * @param numerator The new numerator value.
         */
        void setNumerator(int numerator);

        /**
         * Sets the denominator of the rational number.
         * @param denominator The new denominator value.
         */
        void setDenominator(int denominator);

        /**
         * Gets the numerator of the rational number.
         * @return The numerator value.
         */
        int getNumerator() const;

        /**
         * Gets the denominator of the rational number.
         * @return The denominator value.
         */
        int getDenominator() const;

        /**
         * Displays the rational number in the format "numerator/denominator".
         */
        void display() const;

        /**
         * Adds two rational numbers and returns the result as a new RationalNumber object.
         * @param other The rational number to be added.
         * @return The sum of the two rational numbers.
         */
        RationalNumber operator+(const RationalNumber& other) const;

        /**
         * Subtracts a rational number from another and returns the result as a new RationalNumber object.
         * @param other The rational number to be subtracted.
         * @return The difference between the two rational numbers.
         */
        RationalNumber operator-(const RationalNumber& other) const;

        /**
         * Multiplies two rational numbers and returns the result as a new RationalNumber object.
         * @param other The rational number to be multiplied.
         * @return The product of the two rational numbers.
         */
        RationalNumber operator*(const RationalNumber& other) const;

        /**
         * Divides a rational number by another and returns the result as a new RationalNumber object.
         * @param other The rational number to be divided by.
         * @return The quotient of the two rational numbers.
         */
        RationalNumber operator/(const RationalNumber& other) const;

        /**
         * Checks if two rational numbers are equal.
         * @param other The rational number to be compared.
         * @return True if the two rational numbers are equal, false otherwise.
         */
        bool operator==(const RationalNumber& other) const;

        /**
         * Checks if two rational numbers are not equal.
         * @param other The rational number to be compared.
         * @return True if the two rational numbers are not equal, false otherwise.
         */
        bool operator!=(const RationalNumber& other) const;

        /**
         * Checks if a rational number is less than another.
         * @param other The rational number to be compared.
         * @return True if the first rational number is less than the second, false otherwise.
         */
        bool operator<(const RationalNumber& other) const;

        /**
         * Checks if a rational number is greater than another.
         * @param other The rational number to be compared.
         * @return True if the first rational number is greater than the second, false otherwise.
         */
        bool operator>(const RationalNumber& other) const;

        /**
         * Checks if a rational number is less than or equal to another.
         * @param other The rational number to be compared.
         * @return True if the first rational number is less than or equal to the second, false otherwise.
         */
        bool operator<=(const RationalNumber& other) const;

        /**
         * Checks if a rational number is greater than or equal to another.
         * @param other The rational number to be compared.
         * @return True if the first rational number is greater than or equal to the second, false otherwise.
         */
        bool operator>=(const RationalNumber& other) const;

    private:
        int numerator; // The numerator of the rational number.
        int denominator; // The denominator of the rational number.

        /**
         * Reduces the rational number to its simplest form.
         */
        void reduce();

        /**
         * Calculates the greatest common divisor (GCD) of two numbers.
         * @param num1 The first number.
         * @param num2 The second number.
         * @return The GCD of num1 and num2.
         */
        int gcd(int num1, int num2);
};
/*class RationalNumber {
    public:
        RationalNumber(int, int);
        void setNumerator(int);
        void setDenominator(int);
        int getNumerator() const;
        int getDenominator() const;
        void display() const;
        RationalNumber operator+(const RationalNumber&) const;
        RationalNumber operator-(const RationalNumber&) const;
        RationalNumber operator*(const RationalNumber&) const;
        RationalNumber operator/(const RationalNumber&) const;
        bool operator==(const RationalNumber&) const;
        bool operator!=(const RationalNumber&) const;
        bool operator<(const RationalNumber&) const;
        bool operator>(const RationalNumber&) const;
        bool operator<=(const RationalNumber&) const;
        bool operator>=(const RationalNumber&) const;
    private:
        int numerator;
        int denominator;
        void reduce();
};*/

#endif
