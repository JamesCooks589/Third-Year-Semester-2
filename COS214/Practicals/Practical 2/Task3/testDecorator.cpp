#include "testDecorator.h"

TestDecorator::TestDecorator(TestBed* testBed) : internalTestBed(testBed) {}

TestDecorator::~TestDecorator() {
    delete internalTestBed;
}

TestBed* TestDecorator::getInternalTestBed() {
    return internalTestBed;
}

void TestDecorator::setInternalTestBed(TestBed* internalTestBed) {
    this->internalTestBed = internalTestBed;
}

bool TestDecorator::runTest() {
    return internalTestBed->runTest();
}
