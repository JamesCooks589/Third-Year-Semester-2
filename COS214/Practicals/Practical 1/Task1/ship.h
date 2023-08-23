//Carter Shin u21470864 & James Cooks u21654680
#ifndef SHIP_H
#define SHIP_H

#include <string>

using namespace std;

class ship {
public:
    //Member variables
    string shipName;
    int shipId;

    //Getters
    string getShipName();
    int getShipId();
    //Setters
    void setShipName(string name);
    void setShipId(int id);
protected:
    virtual ship* clone() = 0;
};

#endif