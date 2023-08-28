#pragma once
#include "test.h"

using namespace std;
class booleanTest : public test
{
    public:
        bool executeTest(calculator& calc) const override;
};