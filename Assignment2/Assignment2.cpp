
#include <iostream>
    using namespace std; //enable program to use all the names in std
#include <cstdlib> // program uses exit function

    using std::cout; // program uses cout
    using std::cin; // program uses cin
    using std::endl; // program uses endl

void salesCalculator(); /// Calculates the salary based on the sales amount.
double calculateSalary(double sales); /// Calculates the salary based on the sales amount.
void patternPrinterA(); /// Prints a pattern of stars based on the input.
void patternPrinterB(); /// Prints a pattern of stars based on the input.
void patternPrinterC(); /// Prints a pattern of stars based on the input.
void patternPrinterD(); /// Prints a pattern of stars based on the input.
void salesOrder(); /// Calculates the total sales based on the input.

/**
 * The main function is the entry point of the program.
 * It prompts the user to enter sales in dollars and calculates the corresponding salary.
 * The program continues to prompt the user until the input is -1, indicating the end of the program.
 * After the program ends, it displays a success message and exits.
 */
int main(){
    int input;
    do {
        
        cout << "Choose which program to run by picking a number 1-3 or 0 to quit\t:" << endl;
        cout << "1. Sales Commission Calculator" << endl;
        cout << "2. Pattern printer with nested for loops" << endl;
        cout << "3. Total Sales Calculator" << endl;
        cout << "0. Quit" << endl;
        cin >> input;
        switch(input){
            case 0:
                cout << "Program ended sucessfully" << endl;
                exit(0); // indicate that program ended successfully
            case 1:
                salesCalculator();
                break;
            case 2:
                patternPrinterA();
                patternPrinterB();                
                patternPrinterC();
                patternPrinterD();
                break;
            case 3:
                salesOrder();
                break;
            default:
                cout << "Invalid input, please try again" << endl;
                break;
        }

        cout << "The salary is\t\t\t\t:$" << calculateSalary(input) << endl;


    }while (true);

    cout << "Program ended sucessfully" << endl;

    exit(0); // indicate that program ended successfully
}

/**
 * Calculates the salary based on the sales input.
 * Continuously prompts the user to enter sales in dollars until -1 is entered.
 * Prints the calculated salary for each input.
 * Ends when -1 is entered.
 */
void salesCalculator(){
    double input, sales;
    do {
            cout << "Enter sales in dollars (-1 to end)\t:" ;
            cin >> input;
            if (input == -1 || input == -1.00)    break;

            cout << "The salary is\t\t\t\t:$" << calculateSalary(input) << endl;

        }while (true);
        cout << "Sales Calculator ended sucessfully, back to menu" << endl;
}


/**
 * Calculates the salary based on the sales amount.
 * 
 * @param sales The amount of sales made.
 * @return The calculated salary.
 */
double calculateSalary(double sales){
    return 200 + (sales * 0.09);
}

/**
 * Prints a pattern of stars based on the input.
 * 
 * @param input The number of rows to print.
 */
void patternPrinterA(){
    cout << "Start Pattern A" << endl;
    for (int i = 1; i <= 10; i++){
        for (int j = 1; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
    cout << "End Pattern A" << endl;
}

/**
 * Prints a pattern of stars based on the input.
 * 
 * @param input The number of rows to print.
 */
void patternPrinterB(){
    cout << "Start Pattern B" << endl;
    for (int i = 1; i <= 10; i++){
        for (int j = 10; j >= i; j--){
            cout << "*";
        }
        cout << endl;
    }
    cout << "End Pattern B" << endl;
}

/**
 * Prints a pattern of stars based on the input.
 * 
 * @param input The number of rows to print.
 */
void patternPrinterD(){
    cout << "Start Pattern D" << endl;
    for (int i = 1; i <= 10; i++){
        for (int j = 10; j >= i; j--){
            cout << " ";
        }
        for (int j = 1; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
    cout << "End Pattern D" << endl;
}

/**
 * Prints a pattern of stars based on the input.
 * 
 * @param input The number of rows to print.
 */
void patternPrinterC(){
    cout << "Start Pattern C" << endl;
    for (int i = 1; i <= 10; i++){
        for (int j = 1; j <= i; j++){
            cout << " ";
        }
        for (int j = 10; j >= i; j--){
            cout << "*";
        }
        cout << endl;
    }
    cout << "End Pattern C" << endl;
}

/**
 * Calculates the total sales based on the input.
 * Continuously prompts the user to enter sales in dollars until -1 is entered.
 * Prints the calculated total sales for each input.
 * Ends when -1 is entered.
 */
void salesOrder(){
    double p1= 2.98, p2= 4.50, p3= 9.98, p4= 4.49, p5= 6.87
            , totalSales = 0;
    int inputProduct, inputQuantity;

    do {
            cout << "Enter product number and quantity sold\t:" ;
            cout << "Enter -1 to end" << endl;
            cin >> inputProduct >> inputQuantity;

            switch(inputProduct){
                case -1:
                    break;
                case 1:
                    totalSales += p1 * inputQuantity;
                    break;
                case 2:
                    totalSales += p2 * inputQuantity;
                    break;
                case 3:
                    totalSales += p3 * inputQuantity;
                    break;
                case 4:
                    totalSales += p4 * inputQuantity;
                    break;
                case 5:
                    totalSales += p5 * inputQuantity;
                    break;
                default:
                    cout << "Invalid input for , please try again" << endl;
                    break;
            }
            cout << "The total sales is\t\t\t:$" << totalSales << endl;
            if(inputProduct == -1 || inputQuantity == -1) break;
            
        }while (true);
        cout << "Sales Order ended sucessfully, back to menu" << endl;
}