//Carter Shin u21470864 & James Cooks u21654680
#ifndef WINDOW_H
#define WINDOW_H

#include "primitive.h"

#include <string>

using namespace std;

class Window{
    public:
        int screenheight;
        int screenwidth;
        int primitiveCount;
        int primitiveCapacity;

        int getScreenHeight();
        int getScreenWidth();
        int getPrimitiveCount();
        int getPrimitiveCapacity();

        void setScreenHeight(int height);
        void setScreenWidth(int width);
        void setPrimitiveCount(int count);
        void setPrimitiveCapacity(int capacity);

    protected:
        virtual string toString()=0;
};

#endif