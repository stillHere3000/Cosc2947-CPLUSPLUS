#include <iostream>
#include "Account.h"

using namespace std;

/**
 * @brief Constructs an Account object with the specified balance.
 *
 * This constructor initializes the balance of the Account object. If the specified balance is less than 0.0,
 * the balance is set to 0.0.
 *
 * @param b The initial balance of the Account.
 */
Account::Account( double b ) {
   balance = (b < 0.0) ? 0.0 : b;
}


/**
 * Deposits the specified amount into the account.
 * 
 * @param amount The amount to be deposited.
 */
void Account::deposit( double amount ) {
   balance =(amount >= 0.0)? balance + amount: balance;   
}

/**
 * @brief Withdraws a specified amount from the account balance.
 * 
 * This function subtracts the specified amount from the account balance if the amount is less than or equal to the current balance.
 * If the amount is greater than the current balance, the balance remains unchanged.
 * 
 * @param amount The amount to be withdrawn from the account.
 */
void Account::withdraw( double amount ) {
   balance = (amount <= balance) ? balance - amount: balance;   
}

/**
 * Returns the current balance of the account.
 *
 * @return The balance of the account.
 */
double Account::getBalance() const {
   return balance;
}