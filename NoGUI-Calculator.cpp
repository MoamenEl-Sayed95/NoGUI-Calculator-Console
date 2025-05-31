#include <iostream>
#include <cmath>
#include <limits>
#include <sstream>
using namespace std;

class Calculator
{
public:
    Calculator()
    {
        cout << "Calculator Initialized!" << endl;
    }

    double add(double a, double b)
    {
        return a + b;
    }

    double subtract(double a, double b)
    {
        return a - b;
    }

    double multiply(double a, double b)
    {
        return a * b;
    }

    double divide(double a, double b)
    {
        if (b == 0)
        {
            cout << "Error! Division by zero." << endl;
            return numeric_limits<double>::quiet_NaN();
        }
        return a / b;
    }

    double exponentiate(double a, double b)
    {
        return pow(a, b);
    }
};

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool isInteger(const string &input)
{
    istringstream iss(input);
    int num;
    char extra;
    return (iss >> num) && !(iss >> extra);
}

int main()
{
    Calculator calc;

    while (true)
    {
        cout << "\nSimple Calculator (OOP-Based)" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Exponentiation" << endl;
        cout << "6. Exit" << endl;

        cout << "\nEnter your choice: ";
        string choiceInput;
        getline(cin, choiceInput);

        if (!isInteger(choiceInput))
        {
            cout << "Invalid input! Please enter a number between 1 and 6." << endl;
            continue;
        }

        int choice = stoi(choiceInput);

        if (choice == 6)
        {
            cout << "Exiting Calculator. Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 6)
        {
            cout << "Invalid choice! Please enter a number between 1 and 6." << endl;
            continue;
        }

        double num1, num2;
        cout << "\nEnter a first number: ";
        cin >> num1;
        if (cin.fail())
        {
            cout << "Invalid input! Please enter a valid number." << endl;
            clearInput();
            continue;
        }

        cout << "\nEnter a second number: ";
        cin >> num2;
        if (cin.fail())
        {
            cout << "Invalid input! Please enter a valid number." << endl;
            clearInput();
            continue;
        }
        clearInput(); // لتنظيف إدخال المستخدم بعد الأرقام

        double result;

        switch (choice)
        {
        case 1:
            result = calc.add(num1, num2);
            cout << "\nResult: " << num1 << " + " << num2 << " = " << result << endl;
            break;
        case 2:
            result = calc.subtract(num1, num2);
            cout << "\nResult: " << num1 << " - " << num2 << " = " << result << endl;
            break;
        case 3:
            result = calc.multiply(num1, num2);
            cout << "\nResult: " << num1 << " * " << num2 << " = " << result << endl;
            break;
        case 4:
            result = calc.divide(num1, num2);
            cout << "\nResult: " << num1 << " / " << num2 << " = " << result << endl;
            break;
        case 5:
            result = calc.exponentiate(num1, num2);
            cout << "\nResult: " << num1 << " ^ " << num2 << " = " << result << endl;
            break;
        }
    }

    return 0;
}

// Created By Programmer Moamen Abouhaty
