//Carter Shin u21470864 & James Cooks u21654680
#include "cargoShip.h"
#include <sstream>
#include <iostream>

using namespace std;


string cargoShip::toString() {
    ostringstream oss;
    oss << "Ship " << shipId << ": " << shipName << "\n";
    oss << "load: " << currentLoad << "/" << capacity << "\n";
    oss << "Items:\n";
    for (int i = 0; i < currentLoad; i++) {
        oss << "item " << (i + 1) << ": " << items[i] << "\n";
    }
    return oss.str();
}

//Getters
int cargoShip::getCapacity() {
    return capacity;
}

string* cargoShip::getItems() {
    return items;
}

int cargoShip::getCurrentLoad() {
    return currentLoad;
}

//Setters
void cargoShip::setCapacity(int cap) {
    capacity = cap;
}

void cargoShip::setItems(string* item) {
    items = item;
}

void cargoShip::setCurrentLoad(int load) {
    currentLoad = load;
}

void cargoShip::restore(cargoMemento restorePoint) {
    capacity = restorePoint.getCapacity();
    currentLoad = restorePoint.getCurrentLoad();
    items = restorePoint.getItems();
}

cargoMemento cargoShip::save(int saveId) {
    return cargoMemento(shipName, saveId, capacity, currentLoad, items);
}

ship* cargoShip::clone() {
    //polymorphism, since a cargoShip is a ship we return a new cargoShip object
    cargoShip* newS = new cargoShip();
    newS->setShipName(shipName);
    newS->setShipId(shipId);
    newS->setCapacity(capacity);
    newS->setCurrentLoad(currentLoad);
    newS->setItems(items);
    return newS;
}

void cargoShip::insertItem(string item) {
    if (currentLoad < capacity) {
        items[currentLoad] = item;
        currentLoad++;
    }
    else{
        cout<<"Ship is full!"<<endl;
    }
}

void cargoShip::deleteItem(string item) {
    //loops through the whole array
    for(int j = 0; j < currentLoad; j++){
        //finds the index of where the item we are searching for is
        if(items[j]==item){
            //bubbles up, clears the null in between elements
            for(int i = j; i < currentLoad - 1; i++) {
                items[i] = items[i + 1];            
            }
            currentLoad--;
            break;
        }
        
    }
}
