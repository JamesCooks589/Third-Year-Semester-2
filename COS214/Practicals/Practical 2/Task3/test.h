#pragma once
#include "testable.h"

class Test : public Testable {
public:
    virtual bool executeTest() = 0;
    virtual bool runTest() override;
};
