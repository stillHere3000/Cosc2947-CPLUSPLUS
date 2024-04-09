#include <iostream>
    using namespace std; //enable program to use all the names in std
#include <cstdlib> // program uses exit function
    
        using std::cout; // program uses cout
        using std::cin; // program uses cin
        using std::endl; // program uses endl
        
        void intializeArray(); /// Intialize all element to 1
        void calculateSieve(int []); /// Calculate Sieve of Eratosthenes

        //int array[1000];

/**
 * @brief The main function of the program.
 * 
 * @return int The exit status of the program.
 */
int main(){
    cout << "Intializing All elements to 1\n:" << endl;
    intializeArray();
    cout << "\nProgram ended sucessfully" << endl;
    exit(0); // indicate that program ended successfully
}

/**
 * Initializes an array of size 1000 with all elements set to 1.
 * Then, it calls the calculateSieve function to calculate the Sieve of Eratosthenes.
 */
void intializeArray(){
    int array[1000];
    for(int i = 0; i < 1000; i++){
        array[i] = 1;
    }
    cout << "\nCalculating Sieve of Eratosthenes\n:" << endl;
    calculateSieve(array);
}

/**
 * Calculates the prime numbers using the Sieve of Eratosthenes algorithm.
 * Modifies the given array to mark non-prime numbers as 0.
 * Prints out the prime numbers.
 *
 * @param array The array to be modified and printed.
 */
void calculateSieve(int array[]){
    for(int i = 2; i < 1000; i++){
        if(array[i] == 1){
            for(int j = i + 1; j < 1000; j++){
                if(j % i == 0){
                    array[j] = 0;
                }
            }
        }
    }
    cout << "Printing out prime numbers\n:" << endl;
    int w = 0;
    for(int k = 2; k < 1000; k++){
        if(array[k] == 1){
            cout << k << "\t";  w++;
            flush(cout);
            if (w % 10 == 0){
                cout << "\n";
            }
        }        
    }
}