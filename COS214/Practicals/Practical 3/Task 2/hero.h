#pragma once
#include <iostream>
#include <string>
#include "Iterator.h"
#include "lair.h"
using namespace std;

class hero
{
    private:
        string type;
        int health;
        bool isAlive;
    public:
        hero(string type, int health);
        string getType();
        bool getIsAlive();
        int getHealth();
};