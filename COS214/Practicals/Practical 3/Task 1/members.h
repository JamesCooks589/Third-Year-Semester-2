#ifndef OBSERVINGMEMBERS_H
#define OBSERVINGMEMBERS_H

#include "observer.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Members : public Observer
{
    public:
    Members(string contact);
    virtual ~Members();
    void update(const Contract* c) override;

    private:
    string contact;
};

#endif