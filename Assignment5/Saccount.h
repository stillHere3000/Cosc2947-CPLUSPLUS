// Purpose: Header file for Saccount class
// path: Saccount.h
#ifndef SACCOUNT_H
#define SACCOUNT_H

#include <string>
#include <iostream>

using namespace std;


class Saccount {
public:
    Saccount(std::string, double);
    void deposit(double);
    void withdraw(double);
    void display() const;
    double getBalance() const;
    std::string getName() const;
    static void modifyInterestRate(double);
    void calculateMonthlyInterest();
    
private:
    std::string name;
    double savingsBalance;
    static double annualInterestRate;
};

#endif