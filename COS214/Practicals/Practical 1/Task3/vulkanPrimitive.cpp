//Carter Shin u21470864 & James Cooks u21654680
#include "vulkanPrimitive.h"

string vulkanPrimitive::toString(){
    return "Vulkan " + this->shape + "\n\tX coordinate: " + to_string(this->xcoord) + "\n\tY coordinate: " + to_string(this->ycoord);
}

float vulkanPrimitive::getXcoord(){
    return xcoord;
}

void vulkanPrimitive::setXcoord(float xcoord){
    this->xcoord = xcoord;
}

float vulkanPrimitive::getYcoord(){
    return ycoord;
}

void vulkanPrimitive::setYcoord(float ycoord){
    this->ycoord = ycoord;
}