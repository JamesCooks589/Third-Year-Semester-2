//Carter Shin u21470864 & James Cooks u21654680
#ifndef FACTORY_H
#define FACTORY_H

#include "Window.h"
#include "primitive.h"

using namespace std;

class factory{
    public:
        virtual Window* createWindow()=0;
        virtual primitive* createPrimitive()=0;
};

#endif