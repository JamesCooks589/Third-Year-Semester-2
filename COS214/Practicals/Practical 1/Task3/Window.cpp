//Carter Shin u21470864 & James Cooks u21654680
#include "Window.h"

int Window::getScreenWidth(){
    return screenwidth;
}

void Window::setScreenWidth(int screenwidth){
    this->screenwidth = screenwidth;
}

int Window::getScreenHeight(){
    return screenheight;
}

void Window::setScreenHeight(int screenheight){
    this->screenheight = screenheight;
}

int Window::getPrimitiveCount(){
    return primitiveCount;
}

void Window::setPrimitiveCount(int primitiveCount){
    this->primitiveCount = primitiveCount;
}

int Window::getPrimitiveCapacity(){
    return primitiveCapacity;
}

void Window::setPrimitiveCapacity(int primitiveCapacity){
    this->primitiveCapacity = primitiveCapacity;
}


