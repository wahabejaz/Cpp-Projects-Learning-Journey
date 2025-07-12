//Calculator
//The program performs basic arithmetic operations (addition, subtraction, multiplication, division)
//Programmer Name: Wahab Ejaz
//Compiler: gcc
//Date: 12-Jul-2025

#include <iostream>
#include <limits>
using namespace std;

bool validInput()
{
    if (cin.good()) 
    {
        cin.ignore(1000, '\n');
        return true;
    }
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input. Please Enter Valid Integer." << endl;
    return false;
}

float addition(float num1, float num2)
{
    float sum = num1 + num2;
    return sum;
}

float subtract(float num1, float num2)
{
    float minusN = num1 - num2;
    return minusN;
}

float multiply(float num1, float num2)
{
    float mulN = num1 * num2;
    return mulN;
}

float division(float num1, float num2)
{
    float divN = num1 / num2;
    return divN;
}

int main()
{
    int ch;
    float num1, num2, result;
    do{
    cout <<" _______________________\n";
    cout <<" | ----CALCULATOR----  |\n";
    cout <<" -----------------------\n";
    cout <<" |   1. (+)Add         |\n";
    cout <<" |   2. (-)Subtract    |\n";
    cout <<" |   3. (*)Multiply    |\n";
    cout <<" |   4. (/)Divide      |\n";
    cout <<" |   5. Exit           |\n";
    cout <<" -----------------------\n";
    cout <<" Enter your choice: ";
    cin >> ch;
    cout << endl;

    switch(ch)
    {
        case 1 :
        do{
        cout << "Enter 1st number: ";
        cin >> num1;
        }while(!validInput());
        do{
        cout << "Enter 2nd number: ";
        cin >> num2;
        }while(!validInput());
        result = addition(num1, num2);
        cout << "The sum of " << num1 << " and "<< num2 << " is: " << result << endl;
        break;

        case 2 :
        do{
        cout << "Enter 1st number: ";
        cin >> num1;
        }while(!validInput());
        do{
        cout << "Enter 2nd number: ";
        cin >> num2;
        }while(!validInput());
        result = subtract(num1, num2);
        cout << "The difference of " << num1 << " and "<< num2 << " is: "<< result << endl;
        break;

        case 3 :
        do{
        cout << "Enter 1st number: ";
        cin >> num1;
        }while(!validInput());
        do{
        cout << "Enter 2nd number: ";
        cin >> num2;
        }while(!validInput());
        result = multiply(num1, num2);
        cout << "The product of "<< num1 << " and "<< num2 << " is: "  << result << endl;
        break;

        case 4 :
        do{
        cout << "Enter 1st number: ";
        cin >> num1;
        }while(!validInput());
        do{
        cout << "Enter 2nd number: ";
        cin >> num2;
        if (!validInput()) continue;
        if (num2 == 0)
        cout << "X Dividing with 0 is undefined" << endl;
        }while(num2 == 0);
        result = division(num1, num2);
        cout << "The quotient of "<< num1 << " and "<< num2 << " is: " << result << endl;
        break;

        case 5 :
        cout << "Terminated Successfully!" << endl;
        break;

        default :
        cout << "Invalid choice. Please enter valid integer." << endl;
    }
    }while(ch != 5);

    return 0;
}
