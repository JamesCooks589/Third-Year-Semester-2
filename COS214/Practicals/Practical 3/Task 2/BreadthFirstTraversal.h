#pragma once
#include "Iterator.h"
#include "lair.h"

class DepthFirstTraversal : public Iterator
{
    private:
        Lair* lair;
        int x, y;
    public:
        DepthFirstTraversal(Lair* lair);
        string next();
};