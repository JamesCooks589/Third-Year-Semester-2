//Carter Shin u21470864 & James Cooks u21654680
#include "cargoMemento.h"

using namespace std;

cargoMemento::cargoMemento() : shipId(0), version(0), shipName(""), items(nullptr), currentLoad(0), capacity(0) {}

cargoMemento::cargoMemento(string shipName, int shipId, int capacity, int currentLoad, string* items)
: shipName(shipName), shipId(shipId), capacity(capacity), currentLoad(currentLoad), items(items) {}

//Getters
string cargoMemento::getShipName(){
    return shipName;
}

int cargoMemento::getShipId(){
    return shipId;
}

int cargoMemento::getCapacity(){
    return capacity;
}

int cargoMemento::getCurrentLoad(){
    return currentLoad;
}

string* cargoMemento::getItems(){
    return items;
}

int cargoMemento::getVersion(){
    return version;
}