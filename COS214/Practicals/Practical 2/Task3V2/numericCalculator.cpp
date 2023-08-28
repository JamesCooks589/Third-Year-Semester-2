#include "numericCalculator.h"
#include <iostream>
#include <string>
#include <sstream>

bool numericCalculator::performCalc()
{
    string input = getInputString();
    stringstream ss(input);
    int output, number;
    char operand;

    ss >> output;
    while (ss >> operand >> number)
    {
        switch (operand)
        {
            case '+':
                output += number;
                break;
            case '-':
                output -= number;
                break;
            case '*':
                output *= number;
                break;
            case '/':
                output /= number;
                break;
            default:
                cout << "Invalid operand" << endl;
                return false;
        }
    }
    cout << "Result: " << output << endl;
    return true;

}