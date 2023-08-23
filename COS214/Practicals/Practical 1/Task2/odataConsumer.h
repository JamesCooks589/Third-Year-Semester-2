//Carter Shin u21470864 & James Cooks u21654680
#ifndef ODATACONSUMER_H
#define ODATACONSUMER_H

#include <string>
#include "consumer.h"

using namespace std;

class odataConsumer : public consumer
{
public:
    string parseData(string data);
};

#endif