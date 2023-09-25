#pragma once

#include <iostream>
#include <string>

#include "hero.h"
#include "trap.h"

using namespace std;

//Tile class contains two objects, a hero and a trap
class tile
{
    private:
        hero* heroOnTile;
        trap* trapOnTile;
    public:
        tile();
        void setHero(hero* hero);
        void setTrap(trap* trap);
        hero* getHero();
        trap* getTrap();
        void printTile();
};
    