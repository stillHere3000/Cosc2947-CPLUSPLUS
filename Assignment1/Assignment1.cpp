#include <iostream>
    using namespace std; //enable program to use all the names in std
#include <cstdlib> // program uses exit function

    using std::cout; // program uses cout
    using std::cin; // program uses cin
    using std::endl; // program uses endl

int main() {
    int num1; // first number to be read from user
    int num2; // second number to be read from user
    int num3; // third number to be read from user

    cout << "Enter two integers, and I will tell you\n"
    << "the relationships they satisfy: ";
    cin >> num1 >> num2; // read two integers
    int sum = num1 + num2; // add the numbers; store result in sum
    cout << "Sum is " << sum << endl; // display sum; end line
    int difference = num1 - num2; // subtract the numbers; store result in difference
    cout << "Difference is " << difference << endl; // display difference; end line
    int product = num1 * num2; // multiply the numbers; store result in product
    cout << "Product is " << product << endl; // display product; end line
    int quotient = num1 / num2; // divide the numbers; store result in quotient
    cout << "Quotient is " << quotient << endl; // display quotient; end line

    cout << "Enter three integers, and I will tell you\n"
    << "the relationships they satisfy: ";
    cin >> num1 >> num2 >> num3; // read three integers
    int sum2 = num1 + num2 + num3; // add the numbers; store result in sum
    cout << "Sum is " << sum2 << endl; // display sum; end line
    int average = sum2 / 3; // divide the numbers; store result in average
    int product2 = num1 * num2 * num3; // multiply the numbers; store result in product
    cout << "Product is " << product2 << endl; // display product; end line
    cout << "Average is " << average << endl; // display average; end line
    int smallest = num1; // assume first integer is smallest
    if ( num2 < smallest ) // if second integer is smaller,
        smallest = num2; // assign second integer to smallest
    if ( num3 < smallest ) // if third integer is smaller,
        smallest = num3; // assign third integer to smallest
    cout << "Smallest is " << smallest << endl; // display smallest; end line
    int largest = num1; // assume first integer is largest
    if ( num2 > largest ) // if second integer is larger,
        largest = num2; // assign second integer to largest
    if ( num3 > largest ) // if third integer is larger,
        largest = num3; // assign third integer to largest
    cout << "Largest is " << largest << endl; // display largest; end line

    exit(0); // indicate that program ended successfully
} // end main
