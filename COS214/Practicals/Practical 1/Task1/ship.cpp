//Carter Shin u21470864 & James Cooks u21654680
#include "ship.h"

using namespace std;

//Getters
    string ship::getShipName(){
        return shipName;
    }

    int ship::getShipId(){
        return shipId;
    }

//Setters
    void ship::setShipName(string name){
        shipName = name;
    }

    void ship::setShipId(int id){
        shipId = id;
    }
