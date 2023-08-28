#include "numericTest.h"
#include "numericCalculator.h"

#include <string>
#include <iostream>


bool numericTest::executeTest(calculator& calc) const
{
    numericCalculator* numCalc = dynamic_cast<numericCalculator*>(&calc);
    if (numCalc == nullptr)
    {
        cout << "Calculator is not a numeric calculator" << endl;
        return false;
    }
    else
    {
        return calc.performCalc();
    }
}