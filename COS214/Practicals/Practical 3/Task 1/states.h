#ifndef STATES_H
#define STATES_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

class Contract;

class State 
{
public:
    virtual void addCondition(Contract* c, string condition) = 0;
    virtual void removeCondition(Contract* c, string condition) = 0;
    virtual void accept(Contract* c, string party) = 0;
    virtual void reject(Contract* c) = 0;
    virtual void complete(Contract* c, string party) = 0;
    virtual ~State();
    virtual string getStateName() const = 0;
};

class NegotiationState : public State 
{
public:
    virtual void addCondition(Contract* c, string condition);
    virtual void removeCondition(Contract* c, string condition);
    virtual void accept(Contract* c, string party);
    virtual void reject(Contract* c);
    virtual void complete(Contract* c, string party);
    virtual string getStateName() const;
};

class TentativelyAcceptedState : public State 
{
public:
    virtual void addCondition(Contract* c, string condition);
    virtual void removeCondition(Contract* c, string condition);
    virtual void accept(Contract* c, string party);
    virtual void reject(Contract* c);
    virtual void complete(Contract* c, string party);
    virtual string getStateName() const;
};

class AcceptedState : public State 
{
public:
    virtual void addCondition(Contract* c, string condition);
    virtual void removeCondition(Contract* c, string condition);
    virtual void accept(Contract* c, string party);
    virtual void reject(Contract* c);
    virtual void complete(Contract* c, string party);
    virtual string getStateName() const;
};

class RejectedState : public State 
{
public:
    virtual void addCondition(Contract* c, string condition);
    virtual void removeCondition(Contract* c, string condition);
    virtual void accept(Contract* c, string party);
    virtual void reject(Contract* c);
    virtual void complete(Contract* c, string party);
    virtual string getStateName() const;
};

class CompletedState : public State 
{
public:
    virtual void addCondition(Contract* c, string condition);
    virtual void removeCondition(Contract* c, string condition);
    virtual void accept(Contract* c, string party);
    virtual void reject(Contract* c);
    virtual void complete(Contract* c, string party);
    virtual string getStateName() const;
};

#endif
