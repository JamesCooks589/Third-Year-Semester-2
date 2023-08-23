//Carter Shin u21470864 & James Cooks u21654680
#include "openGLPrimitive.h"

string openGLPrimitive::toString(){
    return "OpenGL " + this->shape + ": \n\tX coordinate: " + to_string(this->xcoord) + "\n\tY coordinate: " + to_string(this->ycoord);
}

int openGLPrimitive::getXcoord(){
    return xcoord;
}

void openGLPrimitive::setXcoord(int xcoord){
    this->xcoord = xcoord;
}

int openGLPrimitive::getYcoord(){
    return ycoord;
}

void openGLPrimitive::setYcoord(int ycoord){
    this->ycoord = ycoord;
}