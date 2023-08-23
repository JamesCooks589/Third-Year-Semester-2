//Carter Shin u21470864 & James Cooks u21654680
#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include "ship.h"
#include "cargoMemento.h"
#include <string>

using namespace std;

class cargoShip : public ship {
public:
    //Member variables
    int capacity;
    string* items;
    int currentLoad;
    //Functions
    string toString();
    cargoMemento save(int saveId);
    void restore(cargoMemento restorePoint);
    ship* clone();
    //Insert and delete items
    void insertItem(string item);
    void deleteItem(string item);
    
    
    //Getters
    int getCapacity();
    string* getItems();
    int getCurrentLoad();
    //Setters
    void setCapacity(int cap);
    void setItems(string* item);
    void setCurrentLoad(int load);
};

#endif