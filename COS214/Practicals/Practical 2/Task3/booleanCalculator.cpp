#include "booleanCalculator.h"

#include <string>
#include <iostream>

using namespace std;

BooleanCalculator::BooleanCalculator(BooleanTest* test) : test(test) {}

BooleanCalculator::~BooleanCalculator() {
    delete test;
}

void BooleanCalculator::runBooleanTest() {
    std::cout << "Running boolean test" << std::endl;
    test->runTest();
}
