//Carter Shin u21470864 & James Cooks u21654680
#include "vulkanFactory.h"

Window* vulkanFactory::createWindow(){
    return new vulkanWindow();
}

primitive* vulkanFactory::createPrimitive(){
    return new vulkanPrimitive();
}
