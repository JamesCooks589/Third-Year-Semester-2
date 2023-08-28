#include "booleanTest.h"
#include "booleanCalculator.h"

#include <string>
#include <iostream>

bool booleanTest::executeTest(calculator& calc) const
{
    booleanCalculator* boolCalc = dynamic_cast<booleanCalculator*>(&calc);
    if (boolCalc == nullptr)
    {
        cout << "Calculator is not a boolean calculator" << endl;
        return false;
    }
    else
    {
        return calc.performCalc();
    }
}
