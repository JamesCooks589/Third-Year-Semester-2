#pragma once
#include "calculator.h"

using namespace std;

class test {
    public :
        virtual bool executeTest(calculator& calc) const = 0;
};