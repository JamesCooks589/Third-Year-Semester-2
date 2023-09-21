#pragma once
#include <string>
using namespace std;

class trap
{
    private:
        string type;
        int damage;
        bool hasBeenTriggered;
    public:
        trap(string type, int damage);
        string getType();
        int getDamage();
        bool getHasBeenTriggered();
        void setHasBeenTriggered(bool hasBeenTriggered);
};