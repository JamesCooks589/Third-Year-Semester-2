#pragma once
#include "test.h"

using namespace std;
class numericTest : public test
{
    public:
        bool executeTest(calculator& calc) const override;
};