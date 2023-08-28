#include "booleanCalculator.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cctype>

using namespace std;

bool booleanCalculator::performCalc(){
    stack<bool> values;
    stack<char> operands;
    string input = getInputString();
    stringstream ss(input);
    char c;

    while(ss >> c){
        if(c == 'T' || c == 'F'){
            values.push(c == 'T');
        }
        else if(c == '('){
            operands.push(c);
        }
        else if(c == ')'){
            while(operands.top() != '('){
                bool val2 = values.top();
                values.pop();
                bool val1 = values.top();
                values.pop();
                char op = operands.top();
                operands.pop();
                values.push(applyOp(val1, val2, op));
            }
            operands.pop();
        }
        else if(c == '&' || c == '|'){
            while(!operands.empty() && hasPrecedence(c, operands.top())){
                bool val2 = values.top();
                values.pop();
                bool val1 = values.top();
                values.pop();
                char op = operands.top();
                operands.pop();
                values.push(applyOp(val1, val2, op));
            }
            operands.push(c);
        }
    }

    while(!operands.empty()){
        bool val2 = values.top();
        values.pop();
        bool val1 = values.top();
        values.pop();
        char op = operands.top();
        operands.pop();
        values.push(applyOp(val1, val2, op));
    }

    cout << "Result: " << values.top() << endl;
    return true;
    
}

bool booleanCalculator::hasPrecedence(char op1, char op2){
    if(op2 == '(' || op2 == ')'){
        return false;
    }
    if((op1 == '&' || op1 == '|') && (op2 == '+' || op2 == '-')){
        return false;
    }
    else{
        return true;
    }
}

bool booleanCalculator::applyOp(bool val1, bool val2, char op){
    if(op == '&'){
        return val1 && val2;
    }
    else if(op == '|'){
        return val1 || val2;
    }
    else{
        cout << "Invalid operand" << endl;
        return false;
    }
}

