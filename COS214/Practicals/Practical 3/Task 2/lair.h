#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "hero.h"
#include "trap.h"
#include "tile.h"
#include "Iterator.h"
#include "BreadthFirstTraversal.h"
#include "DepthFirstTraversal.h"


using namespace std;

class Lair {
    private:
        vector<vector<tile*>> lair;
        int size, x;
        hero* currentHero;
    public:
        Lair();
        Lair(int size);
        ~Lair();
        void printLair();
        void addTrap(int x, int y, trap* trap);
        void addHero(hero* hero);
        hero* getHero();
        void removeHero(int x, int y);
        void removeTrap(int x, int y);
        void increaseSize(int tilesToAdd);
        int getSize();
        //Move hero using iterator
        void moveHero(int x, int y, string direction);
};
