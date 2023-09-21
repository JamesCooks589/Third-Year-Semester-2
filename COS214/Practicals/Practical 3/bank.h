#pragma once
#include <string>
using namespace std;

class bank
{
    private:
        int Gold;
    public:
        bank(int initialGold);
        int getGold();
        void setGold(int gold);
        void performTransaction(int amount, bool isDeposit);
};