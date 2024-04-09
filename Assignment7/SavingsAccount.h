#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {

public:

   explicit SavingsAccount( double = 0.0, double = 0.0 ); // constructor initializes balance and interest rate
   double calculateInterest() const; // determine interest owed

private:
   double interestRate; // interest rate (percentage) earned by the account
};

#endif