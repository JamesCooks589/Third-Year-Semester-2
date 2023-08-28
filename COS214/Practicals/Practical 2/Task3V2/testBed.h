#pragma once
#include "testable.h"
#include "test.h"

using namespace std;
class testBed : public testable
{
    private:
     test* t;

    public:

        test* getTest();
        void setTest(test* test);

        bool runTest(calculator& calc) override;
};