#include "ChequingAccount.h"
#include "Account.h"

/**
 * @brief Constructs a ChequingAccount object with an initial balance and fee.
 *
 * This constructor initializes a ChequingAccount object with the specified initial balance and fee.
 * If the fee is less than 0.0, it is set to 0.0.
 *
 * @param b The initial balance of the ChequingAccount.
 * @param f The fee for each transaction in the ChequingAccount.
 */
ChequingAccount::ChequingAccount( double b, double f ) : Account( b ) {
   fee = (f < 0.0) ? 0.0 : f;
}

/**
 * Deposits the specified amount into the chequing account.
 * 
 * @param amount The amount to be deposited.
 */
void ChequingAccount::deposit( double amount ) {
   Account::deposit( amount + fee );
}

/**
 * @brief Withdraws the specified amount from the chequing account.
 * 
 * This function overrides the withdraw function of the base Account class.
 * It deducts the specified amount plus the fee from the account balance.
 * 
 * @param amount The amount to be withdrawn from the account.
 */
void ChequingAccount::withdraw( double amount ) {
   Account::withdraw( amount - fee );
}