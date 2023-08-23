//Carter Shin u21470864 & James Cooks u21654680
#ifndef OPENGLPRIMITIVE_H
#define OPENGLPRIMITIVE_H

#include <string>
#include "primitive.h"

using namespace std;

class openGLPrimitive: public primitive{
    public:
        int xcoord;
        int ycoord;

        int getXcoord();
        void setXcoord(int xcoord);
        int getYcoord();
        void setYcoord(int ycoord);
        string toString();

};

#endif