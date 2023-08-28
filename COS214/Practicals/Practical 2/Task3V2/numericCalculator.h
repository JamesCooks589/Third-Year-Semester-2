#pragma once
#include "calculator.h"

using namespace std;
class numericCalculator : public calculator
{
    public:
        bool performCalc() override;
};