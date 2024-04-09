// Path: rational.h
#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
public:
    Rational(int = 0, int = 1);
    Rational add(const Rational &) const;
    Rational subtract(const Rational &) const;
    Rational multiply(const Rational &) const;
    Rational divide(const Rational &) const;
    void display() const;
    double toDouble() const;
    std::string toRationalString(int, int) const;

private:
    int numerator;
    int denominator;
    void reduce();
    int gcd(int, int);
};

#endif
