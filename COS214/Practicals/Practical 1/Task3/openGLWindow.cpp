//Carter Shin u21470864 & James Cooks u21654680
#include "openGLWindow.h"
#include <iostream>

openGLWindow::openGLWindow(){
    this->primitives = new openGLPrimitive[3];
    this->primitiveCount = 0;
    this->primitiveCapacity = 3;
}

openGLWindow::~openGLWindow(){
    delete[] this->primitives;
}

string openGLWindow::toString(){
    //cout<<"inside toString openGLWindow"<<endl;
    string result = "OpenGL Window " + to_string(this->screenwidth) + "x" + to_string(this->screenheight) + ":";
    for(int i = 0; i < this->primitiveCount; i++){
        result += "\n\t" + this->primitives[i].toString();
    }
    return result;
}

openGLPrimitive* openGLWindow::getPrimitives(){
    return primitives;
}

void openGLWindow::setPrimitives(openGLPrimitive* primitives){
    this->primitives = primitives;
}

void openGLWindow::addPrimitive(primitive* p) {
    //cout<<"inside addPrimitive openGLWindow"<<endl;
    if (this->primitiveCount < 3) {
        openGLPrimitive* glPrimitive = dynamic_cast<openGLPrimitive*>(p);
        if(glPrimitive!=nullptr){
            this->primitives[this->primitiveCount] = *glPrimitive;
            this->primitiveCount++;
        }
        else{
            cout<<"primitive is not of type openGLPrimitive"<<endl;
        }
    }
    else {
        cout << "The window is full. Cannot add more primitives." << endl;
    }
}