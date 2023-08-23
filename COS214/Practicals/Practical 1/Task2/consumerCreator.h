//Carter Shin u21470864 & James Cooks u21654680
#ifndef CONSUMERCREATOR_H
#define CONSUMERCREATOR_H

#include <string>
#include "consumer.h"

using namespace std;

class consumerCreator
{
public:
    //Member variables
    string consumerType;

    //Functions
    void setConsumer(string type);
    string getConsumer();
    consumer* createConsumer();
};



#endif