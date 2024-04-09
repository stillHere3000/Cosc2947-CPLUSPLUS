#include "SavingsAccount.h"

/**
 * @brief Constructs a SavingsAccount object with an initial balance and interest rate.
 *
 * This constructor initializes a SavingsAccount object with the specified initial balance and interest rate.
 * The initial balance is set using the base class constructor of the Account class.
 * The interest rate is set to the specified value if it is greater than 0.0, otherwise it is set to 0.0.
 *
 * @param b The initial balance of the SavingsAccount.
 * @param r The interest rate of the SavingsAccount.
 */
SavingsAccount::SavingsAccount( double b, double r )  : Account::Account( b ), 
    interestRate{ r > 0.0 ? r : 0.0 } {}

/**
 * Calculates the interest earned on the savings account balance.
 * 
 * @return The interest earned on the savings account balance.
 */
double SavingsAccount::calculateInterest() const {
   return getBalance() * interestRate / 100;
}