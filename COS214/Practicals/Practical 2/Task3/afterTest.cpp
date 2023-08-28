#include "afterTest.h"
#include <string>
#include <iostream>

using namespace std;

AfterTest::AfterTest(TestBed* testBed, const std::string& message) : TestDecorator(testBed), afterMessage(message) {}

bool AfterTest::runTest() {
    bool result = TestDecorator::runTest();
    std::cout << "After Test: " << afterMessage << std::endl;
    return result;
}
