#include "numericCalculator.h"

#include <string>
#include <iostream>

using namespace std;

NumericCalculator::NumericCalculator(NumericTest* test) : test(test) {}

NumericCalculator::~NumericCalculator() {
    delete test;
}

void NumericCalculator::runNumericTest() {
    std::cout << "Running numeric test" << std::endl;
    test->runTest();
}
