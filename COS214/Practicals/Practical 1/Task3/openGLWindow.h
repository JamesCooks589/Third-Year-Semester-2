//Carter Shin u21470864 & James Cooks u21654680
#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include "Window.h"
#include "openGLPrimitive.h"

using namespace std;

class openGLWindow: public Window{
    public:
        openGLWindow();
        ~openGLWindow();
        openGLPrimitive* primitives;
        openGLPrimitive* getPrimitives();
        void setPrimitives(openGLPrimitive* primitives);
        string toString();
        void addPrimitive(primitive* p);
};

#endif