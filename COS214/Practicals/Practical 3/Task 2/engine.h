#pragma once
#include <iostream>
#include <string>

#include "lair.h"
#include "menu.h"
#include "laboratory.h"
#include "bank.h"
#include "storyTeller.h"
#include "hero.h"

using namespace std;

class Engine {
    private:
        Lair* lair;
        Menu* menu;
        Laboratory* laboratory;
        Bank* bank;
        storyTeller* storyTeller;
        int maxWaves;
        int currentWave;
        int turn;
    public:
        Engine(int max);
        ~Engine();
        void startGame();
        void printLair();
        void nextWave();
        void nextTurn();
        void addResearch();
        void addTrap(int x, int y, string type);
        void upgradeTrap();
        void removeUpgradeTrap(string trapName);
        void sellTrap(int x, int y);
        void addGold();
        void getGold();
        void addHero();

};
        



