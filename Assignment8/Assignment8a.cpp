/*
Converting Fahrenheit to Celsius
Write a program that converts Fahrenheit temperatures 0 to 212
degrees to floating-point Celsius temperatures with 3 digits of
precision.  Use the formula:
C = (5/9) * (F - 32)
to perform the calculation.  The output should be printed in two 
right-justified columns and the Celsius temperatures should be
preceded by a '+' or '-' to indicate whether the temperature is 
abover or below freezing.  
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "Fahrenheit" << setw(13) << "Celsius" << endl;
    cout << "----------" << setw(13) << "-------" << endl;
    cout << fixed << setprecision(3);
    for (int fahrenheit = 0; fahrenheit <= 212; fahrenheit++) {
        double celsius = (5.0 / 9.0) * (fahrenheit - 32);
        cout << setw(6) << fahrenheit << setw(13) << ((celsius < 0) ? "-" : "+") << celsius << endl;
    }
    return 0;
}