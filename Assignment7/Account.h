#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {

public:
   explicit Account( double = 0.0 );
   double getBalance() const; // return the account balance
   void deposit( double ); // add an amount to the account balance
   void withdraw( double ); // subtract an amount from the account balance

   

private:

   double balance; // data member that stores the balance
};

#endif