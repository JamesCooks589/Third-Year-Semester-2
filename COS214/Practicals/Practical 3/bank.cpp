#include "bank.h"

Bank::Bank(int initialGold)
{
    Gold = initialGold;
}

int Bank::getGold()
{
    return Gold;
}

void Bank::setGold(int gold)
{
    Gold = gold;
}

void Bank::performTransaction(int amount, bool isDeposit)
{
    if (isDeposit)
    {
        Gold += amount;
    }
    else
    {
        Gold -= amount;
    }
    
}
