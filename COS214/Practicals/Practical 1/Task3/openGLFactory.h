//Carter Shin u21470864 & James Cooks u21654680
#ifndef OPENGLFACTORY_H
#define OPENGLFACTORY_H

#include "factory.h"
#include "OpenGLWindow.h"
#include "OpenGLPrimitive.h"

using namespace std;

class openGLFactory: public factory{
    public:
        Window* createWindow();
        primitive* createPrimitive();
};

#endif