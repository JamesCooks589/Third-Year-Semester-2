#pragma once
#include "testDecorator.h"

#include <string>
#include <iostream>

using namespace std;

class AfterTest : public TestDecorator {
private:
    std::string afterMessage;

public:
    AfterTest(TestBed* testBed, const std::string& message);
    virtual bool runTest() override;
};
