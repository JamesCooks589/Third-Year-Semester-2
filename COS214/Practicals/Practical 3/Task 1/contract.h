#ifndef CONTRACT_H
#define CONTRACT_H

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include "states.h"
#include "observer.h"

using namespace std;

class Observer;

class Contract //subject
{
public:
    Contract(string name, const vector<string>& parties);
    ~Contract();

    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify();
    vector<Observer*> observers;

    void addCondition(string condition);
    void removeCondition(string condition);
    void accept(string party);
    void reject();
    void complete(string party);
    string toString() const;
    void setState(State* state);

    State* state;
    vector<string> conditions;
    string name;
    vector<string> parties;
    vector<string> votes;
};

#endif