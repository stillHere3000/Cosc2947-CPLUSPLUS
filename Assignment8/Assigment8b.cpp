/*
Sizeof Operator
Write a program that uses the sizeof operator to determine 
the sizes in bytes of the various data types on your computer system.
Write the results to a file named size.dat, so that you may print
the results later.  The results should be displayed in two-column 
format with the type name in the left column and trhe size of the type
in the right column.  
char                        1
unsigned char               1
short int                   2
unsigned short int          2
int                         4
unsigned int                4
long int                    4
unsigned long int           4
float                       4
double                      8
long double                 12

*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out("size.dat");
    out << "char" << "\t\t\t\t\t" << sizeof(char) << endl;
    out << "unsigned char" << "\t\t\t" << sizeof(unsigned char) << endl;
    out << "short int" << "\t\t\t\t" << sizeof(short int) << endl;
    out << "unsigned short int" << "\t\t" << sizeof(unsigned short int) << endl;
    out << "int" << "\t\t\t\t\t\t" << sizeof(int) << endl;
    out << "unsigned int" << "\t\t\t" << sizeof(unsigned int) << endl;
    out << "long int" << "\t\t\t\t" << sizeof(long int) << endl;
    out << "unsigned long int" << "\t\t" << sizeof(unsigned long int) << endl;
    out << "float" << "\t\t\t\t\t" << sizeof(float) << endl;
    out << "double" << "\t\t\t\t\t" << sizeof(double) << endl;
    out << "long double" << "\t\t\t\t" << sizeof(long double) << endl;
    out.close();
    return 0;
}