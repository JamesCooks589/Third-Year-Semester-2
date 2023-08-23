//Carter Shin u21470864 & James Cooks u21654680
#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>

class Client {
public:
    //pure virtual function - must be implemented by derived classes
    virtual std::string parseData(const std::string& data) = 0;
    virtual ~Client() {}
    void printData(const std::string& data);        //template method
};

#endif