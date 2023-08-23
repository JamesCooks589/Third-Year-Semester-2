//Carter Shin u21470864 & James Cooks u21654680
#include "vulkanWindow.h"
#include <string>
#include <iostream>

using namespace std;

vulkanWindow::vulkanWindow(){
    this->primitives = new vulkanPrimitive[9];
    this->primitiveCount = 0;
    this->primitiveCapacity = 9;
}

vulkanWindow::~vulkanWindow(){
    delete[] this->primitives;
}

vulkanPrimitive* vulkanWindow::getPrimitives(){
    return primitives;
}

void vulkanWindow::setPrimitives(vulkanPrimitive* primitives){
    this->primitives = primitives;
}

string vulkanWindow::toString(){
    string result = "Vulkan window " + to_string(this->screenwidth) + "x" + to_string(this->screenheight) + ":";
    for(int i = 0; i < this->primitiveCount; i++){
        result += "\n\t" + this->primitives[i].toString();
    }
    return result;
}

void vulkanWindow::addPrimitive(primitive* p) {
    if (this->primitiveCount < 9) {
        vulkanPrimitive* vkPrimitive = dynamic_cast<vulkanPrimitive*>(p);
        if(vkPrimitive!=nullptr){
            this->primitives[this->primitiveCount] = *vkPrimitive;
            this->primitiveCount++;
        }
        else{
            cout<<"primitive is not of type vulkanPrimitive"<<endl;
        }
    }
    else {
        cout << "The window is full. Cannot add more primitives." << endl;
    }
}