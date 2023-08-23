//Carter Shin u21470864 & James Cooks u21654680
#ifndef VULKANPRIMITIVE_H
#define VULKANPRIMITIVE_H

#include "primitive.h"

using namespace std;

class vulkanPrimitive: public primitive{
    public:
        float xcoord;
        float ycoord;

        float getXcoord();
        void setXcoord(float xcoord);
        float getYcoord();
        void setYcoord(float ycoord);
        string toString();
};

#endif