#pragma once
#include "testDecorator.h"

#include <string>
#include <iostream>

using namespace std;

class BeforeTest : public TestDecorator {
private:
    std::string beforeMessage;

public:
    BeforeTest(TestBed* testBed, const std::string& message);
    virtual bool runTest() override;
};
