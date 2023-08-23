//Carter Shin u21470864 & James Cooks u21654680
#ifndef VULKANFACTORY_H
#define VULKANFACTORY_H

#include "vulkanWindow.h"
#include "vulkanPrimitive.h"
#include "factory.h"

using namespace std;

class vulkanFactory: public factory{
    public:
        Window* createWindow();
        primitive* createPrimitive();
};

#endif