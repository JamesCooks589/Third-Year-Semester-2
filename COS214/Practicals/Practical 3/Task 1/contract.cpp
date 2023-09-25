#include "Contract.h"

Contract::Contract(string name, const vector<string>& parties) 
{
    this->name = name;
    this->parties = parties;
    state = new NegotiationState();
}

Contract::~Contract() 
{
    delete state;
}

void Contract::addCondition(string condition) 
{
    state->addCondition(this, condition);
}

void Contract::removeCondition(string condition) 
{
    state->removeCondition(this, condition);
}

void Contract::accept(string party) 
{
    state->accept(this, party);
}

void Contract::reject() 
{
    state->reject(this);
}

void Contract::complete(string party) 
{
    state->complete(this, party);
}

string Contract::toString() const 
{
    string result = "Contract " + name + ":\n";
    result += "State: " + state->getStateName() + "\n";

    if (state->getStateName() == "TENTATIVELY_ACCEPTED" || state->getStateName() == "ACCEPTED") 
    {
        result += "Votes:\n";
        for (const auto& vote : votes) 
        {
            result += vote + "\n";
        }
    }

    result += "Conditions:\n";
    for (const auto& condition : conditions) 
    {
        result += condition + "\n";
    }

    return result;
}

void Contract::setState(State* state_) 
{
   delete state;
   state = state_;
}

void Contract::attach(Observer* observer) 
{
    observers.push_back(observer);
}

void Contract::detach(Observer* observer) 
{
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Contract::notify() 
{
    for (Observer* observer : observers) 
    {
        observer->update(this);
    }
}