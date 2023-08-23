//Carter Shin u21470864 & James Cooks u21654680
#include <iostream>
#include "openGLWindow.h"
#include "openGLPrimitive.h"
#include "Window.h"
#include "primitive.h"
#include "vulkanWindow.h"
#include "vulkanPrimitive.h"

using namespace std;

int main(){

    //factory* openglFactory = new openGLFactory();
    // Window* openglWindow = openglFactory->createWindow();
    // primitive* openglPrimitive = openglFactory->createPrimitive();

    vulkanWindow* window2 = new vulkanWindow();

    // vulkanPrimitive* primitive7 = new vulkanPrimitive[9];
    // window2->setPrimitives(primitive7);
    // cout<<"primitives: "<<window2->getPrimitives()<<endl;


    openGLWindow* window = new openGLWindow();
    window->setScreenWidth(800);
    window->setScreenHeight(600);
    openGLPrimitive* primitive1 = new openGLPrimitive();
    primitive1->setShape("Triangle");
    primitive1->setXcoord(100);
    primitive1->setYcoord(100);
    openGLPrimitive* primitive2 = new openGLPrimitive();
    primitive2->setShape("Square");
    primitive2->setXcoord(200);
    primitive2->setYcoord(200);
    openGLPrimitive* primitive3 = new openGLPrimitive();
    primitive3->setShape("Circle");
    primitive3->setXcoord(300);
    primitive3->setYcoord(300);
    window->addPrimitive(primitive1);
    window->addPrimitive(primitive2);
    window->addPrimitive(primitive3);
    cout<<window->toString()<<endl;

    //adding another primitive to window when it is full
    openGLPrimitive* primitive100 = new openGLPrimitive();
    primitive100->setShape("Triangle");
    primitive100->setXcoord(100);
    primitive100->setYcoord(100);
    window->addPrimitive(primitive100);

    
    window2->setScreenWidth(800);
    window2->setScreenHeight(600);
    vulkanPrimitive* primitive4 = new vulkanPrimitive();
    primitive4->setShape("Triangle");
    primitive4->setXcoord(100);
    primitive4->setYcoord(100);
    vulkanPrimitive* primitive5 = new vulkanPrimitive();
    primitive5->setShape("Square");
    primitive5->setXcoord(200);
    primitive5->setYcoord(200);
    vulkanPrimitive* primitive6 = new vulkanPrimitive();
    primitive6->setShape("Circle");
    primitive6->setXcoord(300);
    primitive6->setYcoord(300);
    window2->addPrimitive(primitive4);
    window2->addPrimitive(primitive5);
    window2->addPrimitive(primitive6);
    cout<<window2->toString()<<endl;

    cout<<"screen width: "<<window->getScreenWidth()<<endl;
    cout<<"screen height: "<<window->getScreenHeight()<<endl;
    cout<<"primitive count: "<<window->getPrimitiveCount()<<endl;
    cout<<"primitive capacity: "<<window->getPrimitiveCapacity()<<endl;
    cout<<"primitives: "<<window->getPrimitives()<<endl;

    cout<<"screen width: "<<window2->getScreenWidth()<<endl;
    cout<<"screen height: "<<window2->getScreenHeight()<<endl;
    cout<<"primitive count: "<<window2->getPrimitiveCount()<<endl;
    cout<<"primitive capacity: "<<window2->getPrimitiveCapacity()<<endl;
    cout<<"primitives: "<<window2->getPrimitives()<<endl;

    return 0;
}



