#pragma once
#include "testable.h"
#include "testBed.h"

using namespace std;
class testDecorator : public testable
{
    private: 
        testBed* internalTestBed;
    public:
        testBed getInternalTestBed();
        void setInternalTestBed(testBed* testBed);

        bool runTest(calculator& calc) override;
        virtual void before() const {}
        virtual void after() const {}
};