#include "lair.h"

Lair::Lair()
{
    //Default size of 5x5
    size = 5;
    //Create a 2D vector of tiles
    for (int i = 0; i < size; i++)
    {
        vector<tile*> row;
        for (int j = 0; j < size; j++)
        {
            row.push_back(new tile());
        }
        lair.push_back(row);
    }
    //Set the current hero to NULL
    currentHero = NULL;

}

Lair::Lair(int size)
{
    //Set the size of the lair
    this->size = size;
    //Create a 2D vector of tiles
    for (int i = 0; i < size; i++)
    {
        vector<tile*> row;
        for (int j = 0; j < size; j++)
        {
            row.push_back(new tile());
        }
        lair.push_back(row);
    }
    //Set the current hero to NULL
    currentHero = NULL;
}

Lair::~Lair()
{
    //Delete all the tiles in the lair
    for (int i = 0; i < lair.size(); i++)
    {
        for (int j = 0; j < lair[i].size(); j++)
        {
            delete lair[i][j];
        }
    }
    //Delete the lair
    lair.clear();
}

void Lair::printLair()
{
    //Print the lair
    for (int i = 0; i < lair.size(); i++)
    {
        for (int j = 0; j < lair[i].size(); j++)
        {
            cout << "Tile " << i << "," << j << endl;
            lair[i][j]->printTile();
        }
    }
}

void Lair::addTrap(int x, int y, trap* trap)
{
    //Add a trap to a tile
    lair[x][y]->setTrap(trap);
}

void Lair::addHero(hero* hero)
{
    //Always add hero to the top left tile
    lair[0][0]->setHero(hero);
}

hero* Lair::getHero()
{
    //Return the current hero
    return currentHero;
}

void Lair::removeHero(int x, int y)
{
    //Remove the hero from the tile
    lair[x][y]->setHero(NULL);
}

void Lair::removeTrap(int x, int y)
{
    //Remove the trap from the tile
    lair[x][y]->setTrap(NULL);
}

void Lair::increaseSize(int tilesToAdd)
{
    //Increase the size of the lair
    size += tilesToAdd;
    //Add new tiles to the lair by deep copying the old lair and adding new tiles to both rows and columns
    vector<vector<tile*>> newLair;
    for (int i = 0; i < size; i++)
    {
        vector<tile*> row;
        for (int j = 0; j < size; j++)
        {
            if (i < lair.size() && j < lair[i].size())
            {
                row.push_back(lair[i][j]);
            }
            else
            {
                row.push_back(new tile());
            }
        }
        newLair.push_back(row);
    }
    //Delete the old lair
    for (int i = 0; i < lair.size(); i++)
    {
        for (int j = 0; j < lair[i].size(); j++)
        {
            delete lair[i][j];
        }
    }
    lair.clear();
    //Set the lair to the new lair
    lair = newLair;
}

int Lair::getSize()
{
    return size;
}

void Lair::moveHero(int x, int y, string direction)
{
    //Move hero one tile in the specified direction (down or right or up or left)
    if (direction == "down")
    {
        //Check if the hero is on the bottom row
        if (x == size - 1)
        {
            cout << "Hero cannot move down" << endl;
        }
        else
        {
            //Check if the tile below the hero is empty
            if (lair[x + 1][y]->getHero() == NULL)
            {
                //Move the hero to the tile below
                lair[x + 1][y]->setHero(lair[x][y]->getHero());
                lair[x][y]->setHero(NULL);
            }
            else
            {
                cout << "Hero cannot move down" << endl;
            }
        }
    }
    else if (direction == "right")
    {
        //Check if the hero is on the rightmost column
        if (y == size - 1)
        {
            cout << "Hero cannot move right" << endl;
        }
        else
        {
            //Check if the tile to the right of the hero is empty
            if (lair[x][y + 1]->getHero() == NULL)
            {
                //Move the hero to the tile to the right
                lair[x][y + 1]->setHero(lair[x][y]->getHero());
                lair[x][y]->setHero(NULL);
            }
            else
            {
                cout << "Hero cannot move right" << endl;
            }
        }
    }
    else if (direction == "up")
    {
        //Check if the hero is on the top row
        if (x == 0)
        {
            cout << "Hero cannot move up" << endl;
        }
        else
        {
            //Check if the tile above the hero is empty
            if (lair[x - 1][y]->getHero() == NULL)
            {
                //Move the hero to the tile above
                lair[x - 1][y]->setHero(lair[x][y]->getHero());
                lair[x][y]->setHero(NULL);
            }
            else
            {
                cout << "Hero cannot move up" << endl;
            }
        }
    }
    else if (direction == "left")
    {
        //Check if the hero is on the leftmost column
        if (y == 0)
        {
            cout << "Hero cannot move left" << endl;
        }
        else
        {
            //Check if the tile to the left of the hero is empty
            if (lair[x][y - 1]->getHero() == NULL)
            {
                //Move the hero to the tile to the left
                lair[x][y - 1]->setHero(lair[x][y]->getHero());
                lair[x][y]->setHero(NULL);
            }
            else
            {
                cout << "Hero cannot move left" << endl;
            }
        }
    }
    else
    {
        cout << "Invalid direction" << endl;
    }

}
