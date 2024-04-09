#include <iostream>
#include <iomanip>
#include "ChequingAccount.h"
#include "SavingsAccount.h"

using namespace std;

int main() {

   Account acc{ 5000.0 };
   SavingsAccount savAccount{ 3000.0, 3.0 };
   ChequingAccount chqAccount{ 1500.0, 0.5 };

   cout << fixed << setprecision( 2 )
      << "Account: $" << acc.getBalance()
      << "\nSavingsAccount: $" << savAccount.getBalance()
      << "\nCheckingAccount: $" << chqAccount.getBalance() << endl;

   acc.deposit( 500.0 );
   savAccount.deposit( savAccount.calculateInterest() );
   chqAccount.deposit( 175.0 );

   cout << "\nAdded $500 to Account: $" << acc.getBalance()
      << "\nAdded interest to SavingsAccount: $" << savAccount.getBalance()
      << "\nAdded $175 to CheckingAccount: $" << chqAccount.getBalance()
      << endl;

   acc.withdraw( 2498.0 );
   savAccount.withdraw( 799.0 );
   chqAccount.withdraw( 600 );

   cout << "\nWithdrawing $2498 Account: $" << acc.getBalance()
      << "\nWithdrawing $799 SavingsAccount: $" << savAccount.getBalance()
      << "\nWithdrawing $600 CheckingAccount: $" << chqAccount.getBalance() << endl;

   return 0;
}