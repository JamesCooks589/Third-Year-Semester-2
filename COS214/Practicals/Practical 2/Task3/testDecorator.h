#pragma once
#include "testBed.h"

class TestDecorator : public Testable {
private:
    TestBed* internalTestBed;

public:
    TestDecorator(TestBed* testBed);
    ~TestDecorator();

    TestBed* getInternalTestBed();
    void setInternalTestBed(TestBed* internalTestBed);

    virtual bool runTest() override;
};
