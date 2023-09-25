#pragma once
#include <iostream>
#include <string>
#include "lair.h"
#include "hero.h"

using namespace std;

class storyTeller {
    private:
        //Array to hold hero objects
        hero** heroes;
    public:
        //Constructor takes a pointer to the lair
        storyTeller(Lair* lair, int maxWaves);
        ~storyTeller();
        void startGame();
        void printLair();
        void createNewHero(int currentWave);

};

        