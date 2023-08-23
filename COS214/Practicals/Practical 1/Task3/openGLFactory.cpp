//Carter Shin u21470864 & James Cooks u21654680
#include "openGLFactory.h"

Window* openGLFactory::createWindow(){
    return new openGLWindow();
}

primitive* openGLFactory::createPrimitive(){
    return new openGLPrimitive();
}