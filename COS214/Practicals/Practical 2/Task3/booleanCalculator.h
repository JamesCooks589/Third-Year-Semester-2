#pragma once
#include "calculator.h"
#include "booleanTest.h"

class BooleanCalculator : public Calculator {
private:
    BooleanTest* test;

public:
    BooleanCalculator(BooleanTest* test);
    ~BooleanCalculator();

    void runBooleanTest();
};
