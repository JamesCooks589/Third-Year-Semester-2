#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "hero.h"
#include "trap.h"
#include "Iterator.h"
#include "BreadthFirstTraversal.h"
#include "DepthFirstTraversal.h"


using namespace std;

class Lair {
    private:
        vector<vector<char>> lair;
        int size, x;
        hero* currentHero;
    public:
        Lair();
        Lair(int size);
        ~Lair();
        void printLair();
        void addTrap(int x, int y, trap* trap);
        void addHero(int x, int y, hero* hero);
        hero* getHero();
        void setHero(hero* hero);
        void removeHero(int x, int y);
        void removeTrap(int x, int y);
        void increaseSize(int tilesToAdd);
        void decreaseSize(int tilesToRemove);
        int getSize();
        //Move hero using iterator
        void moveHero(int x, int y, string direction);
};
