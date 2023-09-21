#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "hero.h"

using namespace std;

class Lair {
    private:
        vector<vector<char>> lair;
        int size, x;
    public:
        Lair();
        Lair(int size);
        ~Lair();
        void printLair();
        void addTrap(int x, int y);
        void addHero(int x, int y, hero* hero);
        void moveHero(int x, int y, int newX, int newY);
        void removeHero(int x, int y);
        void removeTrap(int x, int y);
        void increaseSize(int tilesToAdd);
        void decreaseSize(int tilesToRemove);
        int getSize();
};
