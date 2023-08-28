#include "testBed.h"

TestBed::TestBed(Testable* test) : test(test) {}

TestBed::~TestBed() {
    delete test;
}

Testable* TestBed::getTest() {
    return test;
}

void TestBed::setTest(Testable* test) {
    this->test = test;
}

bool TestBed::runTest() {
    return test->runTest();
}
