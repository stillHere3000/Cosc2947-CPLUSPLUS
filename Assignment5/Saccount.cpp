/*
    * Saccount.cpp
    *
    *  Created on: 2021-10-20
    * 
    * */

#include <iostream>
#include "Saccount.h"

using namespace std;

/**
 * @brief The main function that demonstrates the usage of the Saccount class.
 * 
 * @return int The exit status of the program.
 */
int main() {
    Saccount s1("Saver 1", 2000);
    Saccount s2("Saver 2", 4000);
    

    Saccount::modifyInterestRate(0.03);
    s1.calculateMonthlyInterest();
    s2.calculateMonthlyInterest();
    
    
    cout << "Saver 1: " << s1.getName() << " has a balance of " << s1.getBalance() << endl;
    cout << "Saver 2: " << s2.getName() << " has a balance of " << s2.getBalance() << endl;

    Saccount::modifyInterestRate(0.04);
    s1.calculateMonthlyInterest();
    s2.calculateMonthlyInterest();
    cout << "Saver 1: " << s1.getName() << " has a balance of " << s1.getBalance() << endl;
    cout << "Saver 2: " << s2.getName() << " has a balance of " << s2.getBalance() << endl;
    
}



    double Saccount::annualInterestRate = 0.0; // initialize the static variable

    /**
     * @brief Constructs a new Saccount object with the given name and balance.
     * 
     * @param nm The name of the account holder.
     * @param bal The initial balance of the account.
     */
    Saccount::Saccount(std::string nm, double bal){

        name = nm;
        savingsBalance = bal;
    }

    /**
     * @brief Deposits the specified amount into the savings account.
     * 
     * @param amt The amount to be deposited.
     */
    void Saccount::deposit(double amt){
        savingsBalance += amt;

    }

    /**
     * @brief Withdraws a specified amount from the savings account balance.
     * 
     * @param amt The amount to be withdrawn.
     */
    void Saccount::withdraw(double amt){
        savingsBalance -= amt;
    }

    /**
     * Displays the name and balance of the Saccount.
     */
    void Saccount::display() const{
        cout << "Name: " << name << " Balance: " << savingsBalance << endl;
    }

    /**
     * @brief Get the balance of the savings account.
     * 
     * @return The balance of the savings account.
     */
    double Saccount::getBalance() const{
        return savingsBalance;
    }

    /**
     * @brief Get the name of the Saccount.
     * 
     * @return std::string The name of the Saccount.
     */
    std::string Saccount::getName() const{
        return name;
    }

    /**
     * @brief Modifies the interest rate for the Saccount.
     * 
     * This function allows the user to modify the annual interest rate for the Saccount.
     * The new interest rate is set by the provided rate parameter.
     * 
     * @param rate The new interest rate to be set.
     */
    void Saccount::modifyInterestRate(double rate){
        Saccount::annualInterestRate = rate;
    }

    /**
     * Calculates the monthly interest for the savings account.
     * The interest is calculated based on the current balance and the annual interest rate.
     * The calculated interest is added to the savings balance.
     */
    void Saccount::calculateMonthlyInterest(){
        savingsBalance += (savingsBalance * Saccount::annualInterestRate) / 12;
    }

    

    
    

