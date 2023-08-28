#include "beforeTest.h"

#include <string>
#include <iostream>

using namespace std;

BeforeTest::BeforeTest(TestBed* testBed, const std::string& message) : TestDecorator(testBed), beforeMessage(message) {}

bool BeforeTest::runTest() {
    std::cout << "Before Test: " << beforeMessage << std::endl;
    return TestDecorator::runTest();
}
