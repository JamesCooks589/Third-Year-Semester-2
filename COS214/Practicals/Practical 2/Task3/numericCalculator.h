#pragma once
#include "calculator.h"
#include "numericTest.h"

class NumericCalculator : public Calculator {
private:
    NumericTest* test;

public:
    NumericCalculator(NumericTest* test);
    ~NumericCalculator();

    void runNumericTest();
};
