//Carter Shin u21470864 & James Cooks u21654680
#ifndef CARGOMEMENTO_H
#define CARGOMEMENTO_H

#include <string>

using namespace std;

class cargoMemento {
private:
    string shipName;
    int capacity;
    int currentLoad;
    string* items;

public:
    int shipId;
    int version;
    cargoMemento();
    cargoMemento(string shipName, int shipId, int capacity, int currentLoad, string* items);

    //Getters
    string getShipName();
    int getShipId();
    int getCapacity();
    int getCurrentLoad();
    string* getItems();
    int getVersion();
};

#endif