#ifndef CHEQUINGACCOUNT_H
#define CHEQUINGACCOUNT_H

#include "Account.h"

class ChequingAccount : public Account {

public:
   explicit ChequingAccount( double = 0.0, double = 0.0 ); // constructor initializes balance and transaction fee
   void deposit( double ); // redefined deposit function
   void withdraw( double ); // redefined withdraw function

private:
   double fee; // transaction fee charged for each withdrawal
};

#endif