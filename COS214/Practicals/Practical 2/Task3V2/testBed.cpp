#include "testBed.h"

test* testBed::getTest()
{
    return t;
}

void testBed::setTest(test* test)
{
    this->t = test;
}

bool testBed::runTest(calculator& calc)
{
    //Assumptions: test is not null & calculator is not null & 'executeTest' is a function in test
    return t->executeTest(calc);
}