#pragma once
#include <string>
using namespace std;

class Bank
{
    private:
        int Gold;
    public:
        Bank(int initialGold);
        int getGold();
        void setGold(int gold);
        void performTransaction(int amount, bool isDeposit);
};