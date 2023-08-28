#pragma once

#include "calculator.h"

using namespace std;
class booleanCalculator : public calculator
{
    public:
        bool performCalc() override;
        bool hasPrecedence(char op1, char op2);
        bool applyOp(bool a, bool b, char op);
};