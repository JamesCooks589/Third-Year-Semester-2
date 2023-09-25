#include "hero.h"

hero::hero(string type, int health)
{
    this->type = type;
    this->health = health;
    this->isAlive = true;
    cout << "A " << this->type << " has been created with " << this->health << " health." << endl;
}

string hero::getType()
{
    return this->type;
}

bool hero::getIsAlive()
{
    return this->isAlive;
}

int hero::getHealth()
{
    return this->health;
}
