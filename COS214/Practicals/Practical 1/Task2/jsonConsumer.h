//Carter Shin u21470864 & James Cooks u21654680
#ifndef JSONCONSUMER_H
#define JSONCONSUMER_H

#include <string>
#include "consumer.h"

using namespace std;

class jsonConsumer : public consumer
{
public:
    //Member variables
    string parseData(string data);
};

#endif