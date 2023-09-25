#include "members.h"
#include "contract.h"
#include <iostream>

using namespace std;

Members::Members(string c)
{
    this->contact = c;
}

Members::~Members()
{
}

void Members::update(const Contract* c)
{
    cout << "Nofication to " << contact << " has been sent" << endl;
    cout << "Contract " << c->name << " has been updated to " << c->state->getStateName() << endl;
}