//Carter Shin u21470864 & James Cooks u21654680
#ifndef CONSUMER_H
#define CONSUMER_H

#include <string>
#include <sstream>
using namespace std;

class consumer
{
public:
    string printData(string data);

protected:
    virtual string parseData(string data) = 0;
};

#endif