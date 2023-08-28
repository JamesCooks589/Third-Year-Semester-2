#include "testDecorator.h"
#include <iostream>


testBed testDecorator::getInternalTestBed()
{
    return *internalTestBed;
}

void testDecorator::setInternalTestBed(testBed* testBed)
{
    this->internalTestBed = testBed;
}

bool testDecorator::runTest(calculator& calc)
{
    before();
    bool result = internalTestBed->runTest(calc);
    if (result)
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;
    }
    
    after();
    return result;
}