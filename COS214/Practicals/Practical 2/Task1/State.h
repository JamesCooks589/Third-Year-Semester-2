#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

class Contract;

//#include "Contract.h"

class State {
public:
    virtual void addCondition(Contract* c, std::string condition) = 0;
    virtual void removeCondition(Contract* c, std::string condition) = 0;
    virtual void acceptContract(Contract* c, std::string party) = 0;
    virtual void rejectContract(Contract* c) = 0;
    virtual void completeContract(Contract* c, std::string party) = 0;
    virtual ~State();
    virtual std::string getStateName() const = 0;
};

class NegotiationState : public State {
public:
    virtual void addCondition(Contract* c, std::string condition);
    virtual void removeCondition(Contract* c, std::string condition);
    virtual void acceptContract(Contract* c, std::string party);
    virtual void rejectContract(Contract* c);
    virtual void completeContract(Contract* c, std::string party);
    virtual std::string getStateName() const;
};

class TentativelyAcceptedState : public State {
public:
    virtual void addCondition(Contract* c, std::string condition);
    virtual void removeCondition(Contract* c, std::string condition);
    virtual void acceptContract(Contract* c, std::string party);
    virtual void rejectContract(Contract* c);
    virtual void completeContract(Contract* c, std::string party);
    virtual std::string getStateName() const;
};

class AcceptedState : public State {
public:
    virtual void addCondition(Contract* c, std::string condition);
    virtual void removeCondition(Contract* c, std::string condition);
    virtual void acceptContract(Contract* c, std::string party);
    virtual void rejectContract(Contract* c);
    virtual void completeContract(Contract* c, std::string party);
    virtual std::string getStateName() const;
};

class RejectedState : public State {
public:
    virtual void addCondition(Contract* c, std::string condition);
    virtual void removeCondition(Contract* c, std::string condition);
    virtual void acceptContract(Contract* c, std::string party);
    virtual void rejectContract(Contract* c);
    virtual void completeContract(Contract* c, std::string party);
    virtual std::string getStateName() const;
};

class CompletedState : public State {
public:
    virtual void addCondition(Contract* c, std::string condition);
    virtual void removeCondition(Contract* c, std::string condition);
    virtual void acceptContract(Contract* c, std::string party);
    virtual void rejectContract(Contract* c);
    virtual void completeContract(Contract* c, std::string party);
    virtual std::string getStateName() const;
};

#endif
