#include "tile.h"

tile::tile()
{
    trapOnTile = NULL;
    heroOnTile = NULL;
}

void tile::setHero(hero* hero)
{
    heroOnTile = hero;
}

void tile::setTrap(trap* trap)
{
    trapOnTile = trap;
}

hero* tile::getHero()
{
    return heroOnTile;
}

trap* tile::getTrap()
{
    return trapOnTile;
}

void tile::printTile()
{
    if (heroOnTile != NULL && trapOnTile != NULL)
    {
        cout << "Hero: " << heroOnTile->getType() << " Health: " << heroOnTile->getHealth() << " Alive: " << heroOnTile->getIsAlive() << endl;
    }
    else if (heroOnTile != NULL && trapOnTile == NULL)
    {
        cout << "Hero: " << heroOnTile->getType() << " Health: " << heroOnTile->getHealth() << " Alive: " << heroOnTile->getIsAlive() << endl;
    }
    else if (heroOnTile == NULL && trapOnTile != NULL)
    {
        cout << "Trap: " << trapOnTile->getType() << " Damage: " << trapOnTile->getDamage() << endl;
    }
    else if (heroOnTile == NULL && trapOnTile == NULL)
    {
        cout << "Empty Tile" << endl;

    }
    
}
