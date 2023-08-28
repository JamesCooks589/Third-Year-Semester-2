#pragma once
#include "testable.h"

class TestBed {
private:
    Testable* test;

public:
    TestBed(Testable* test);
    ~TestBed();

    Testable* getTest();
    void setTest(Testable* test);

    bool runTest();
};
