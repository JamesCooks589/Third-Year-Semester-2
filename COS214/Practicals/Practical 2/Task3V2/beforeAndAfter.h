#pragma once
#include "TestDecorator.h"

using namespace std;
class beforeAndAfter : public testDecorator
{
    public:
        void before() const override;
        void after() const override;
};