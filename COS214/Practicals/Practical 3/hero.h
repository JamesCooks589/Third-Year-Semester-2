#pragma once
#include <string>
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
        void move(string type);
};