#pragma once
#include "calculator.h"
#include <string>

using namespace std;

class testable
{
public: 
    virtual ~testable() {};

    virtual bool runTest(calculator& calc) = 0;
};
