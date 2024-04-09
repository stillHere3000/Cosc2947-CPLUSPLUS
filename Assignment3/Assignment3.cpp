
#include <iostream>
    using namespace std; //enable program to use all the names in std
#include <cstdlib> // program uses exit function

    using std::cout; // program uses cout
    using std::cin; // program uses cin
    using std::endl; // program uses endl
    enum class Guess {TOO_LOW=-1, CORRECT, TOO_HIGH};

    void numberGuesser(); /// Calculates the salary based on the sales amount.
    int recursiveExponent(int, int); /// Calculates the salary based on the sales amount.


int main(){
    int guess; // user's guess
    int answer = rand() % 1000 + 1; // random number between 1 and 1000
    int input; 
    int base, exponent;

    int result_of_guess;  
    cout << "Guess a number between 1 and 1000" << endl;

    do{
        
        cout << "Choose which program to run by picking a number 1-2 or 0 to quit\t:" << endl;
        cout << "1. Number Guesser" << endl;
        cout << "2. Recursion" << endl;       
        cout << "0. Quit" << endl;
        cin >> input;
        switch(input){
            case 0:
                cout << "Program ended sucessfully" << endl;
                exit(0); // indicate that program ended successfully
            case 1:
                numberGuesser();
                break;

            case 2:                
                cout << "Enter the base: ";
                cin >> base;
                cout << "Enter the exponent: ";
                cin >> exponent;
                recursiveExponent(base, exponent);
                cout << base << " raised to the " << exponent << " power is " << recursiveExponent(base, exponent) << endl;
                break;
           
            default:
                cout << "Invalid input, please try again" << endl;
                break;
        }

    }while(true);
    

}

void numberGuesser(){
    int guess; // user's guess
    int answer = rand() % 1000 + 1; // random number between 1 and 1000

    int result_of_guess;  
    cout << "Guess a number between 1 and 1000" << endl;

    do{
        
        cin >> guess;
        result_of_guess = guess - answer ;
        if (guess == answer){
            cout << "You guessed correctly!" << endl;
            Guess::CORRECT;
            break;
        }
        else if (guess < answer){
            cout << "Your guess of " << guess << " is too low" << endl;
        }
        else if (guess > answer){
            cout << "Your guess " << guess << " is too high" << endl;
        }

    }while(true);

    cout << "The answer was " << answer << endl;
    cout << "You guess of  " << guess << " was correct "<< endl;
    cout << "Program ended sucessfully" << endl;
}

int recursiveExponent(int base , int exponent){

    // base case
    if (exponent == 0){
        return 1;
    }
    // recursive step
    else{
        return base * recursiveExponent(base, exponent - 1);
    }
    
    
}