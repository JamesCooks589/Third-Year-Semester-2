#pragma once
#include <iostream>
#include <string>
#include "lair.h"
#include "hero.h"
#include "engine.h"

using namespace std;

class Menu {
    private:
        Lair* lair;
        hero* hero;
        Engine* engine;
    public:
        Menu(Engine* engine);
        ~Menu();
        void upgradeTrap();
        void removeUpgradeTrap(string trapName);
        void addTrap(int x, int y, string type);
        void sellTrap(int x, int y);
        void increaseLairSize();
        void decreaseLairSize();
        void getGold();
        void startGame();


};