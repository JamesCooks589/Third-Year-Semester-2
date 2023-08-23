//Carter Shin u21470864 & James Cooks u21654680
#ifndef VULKANWINDOW_H
#define VULKANWINDOW_H

#include "Window.h"
#include "vulkanPrimitive.h"

using namespace std;

class vulkanWindow: public Window{
    public:
        vulkanWindow();
        ~vulkanWindow();
        vulkanPrimitive* primitives;
        vulkanPrimitive* getPrimitives();
        void setPrimitives(vulkanPrimitive* primitives);
        string toString();
        void addPrimitive(primitive* p);
};

#endif