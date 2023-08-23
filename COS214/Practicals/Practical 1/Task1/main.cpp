//Carter Shin u21470864 & James Cooks u21654680
#include <iostream>
#include "ship.h"
#include "cargoship.h"
#include "cargomemento.h"

int main() {
    cargoShip myShip;
    string* strList = new string[5];
    for (int i = 0; i < 5; i++)
    {
        strList[i] = "cargo ";
        strList[i] += to_string(i);
    }

    myShip.setShipName("Boaty McBoatface");
    myShip.setShipId(1);
    myShip.setCapacity(5);
    myShip.setItems(strList);
    myShip.setCurrentLoad(5);

    std::cout << myShip.toString() << std::endl;

    cargoMemento newMemento;
    newMemento = myShip.save(1); 
    for (int i = 0; i < 5; i++)
    {
        strList[i] = "cargo ";
        strList[i] += to_string(rand() % 100);
    }

    myShip.setShipName("Titanic");
    myShip.setShipId(2);
    myShip.setCapacity(3);
    myShip.setItems(strList);
    myShip.setCurrentLoad(3);

    std::cout << myShip.toString() << std::endl;

    myShip.restore(newMemento);

    std::cout << myShip.toString() << std::endl;

    return 0;
}