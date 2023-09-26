#include "states.h"
#include "contract.h"

State::~State() {}

void NegotiationState::addCondition(Contract* c, string condition) 
{
    c->conditions.push_back(condition);
}   

void NegotiationState::removeCondition(Contract* c, string condition) 
{
    auto iterator = find(c->conditions.begin(), c->conditions.end(), condition);
    if (iterator != c->conditions.end()) 
    {
        c->conditions.erase(iterator);
    }
}

void NegotiationState::accept(Contract* c, string party) 
{
    c->setState(new TentativelyAcceptedState());
    c->votes.push_back(party);
}

void NegotiationState::reject(Contract* c) 
{
    c->setState(new RejectedState());
}

void NegotiationState::complete(Contract* c, string party) 
{
    throw runtime_error("Cannot complete contract in current state");
}

string NegotiationState::getStateName() const 
{
    return "NEGOTIATION";
}

void TentativelyAcceptedState::addCondition(Contract* c, string condition) 
{
    c->setState(new NegotiationState());
    c->conditions.push_back(condition);
    c->votes.clear();
}

void TentativelyAcceptedState::removeCondition(Contract* c, string condition) 
{
    auto iterator = find(c->conditions.begin(), c->conditions.end(), condition);
    if (iterator != c->conditions.end()) 
    {
        c->conditions.erase(iterator);
    }
    c->setState(new NegotiationState());
    c->votes.clear();
}

void TentativelyAcceptedState::accept(Contract* c, string party) 
{
    if(find(c->parties.begin(), c->parties.end(), party) == c->parties.end()) 
    {
        throw runtime_error("Party not involved in contract");
    }
    if(c->votes.size() == c->parties.size()) 
    {
        c->setState(new AcceptedState());
    }
}

void TentativelyAcceptedState::reject(Contract* c) 
{
    throw runtime_error("Cannot reject contract");
}

void TentativelyAcceptedState::complete(Contract* c, string party) 
{
    throw runtime_error("Cannot complete contract");
}

string TentativelyAcceptedState::getStateName() const 
{
    return "TENTATIVELY_ACCEPTED";
}

void AcceptedState::addCondition(Contract* c, string condition) 
{
    throw runtime_error("Cannot add condition to contract");
}

void AcceptedState::removeCondition(Contract* c, string condition) 
{
    throw runtime_error("Cannot remove condition from contract");
}

void AcceptedState::accept(Contract* c, string party) 
{
    throw runtime_error("Cannot accept contract");
}

void AcceptedState::reject(Contract* c) 
{
    throw runtime_error("Cannot reject contract");
}

void AcceptedState::complete(Contract* c, string party) 
{
    if(find(c->parties.begin(), c->parties.end(), party) == c->parties.end()) 
    {
        throw runtime_error("Party not involved");
    }
    if(c->votes.size() == c->parties.size()) 
    {
        c->setState(new CompletedState());
    }
}

string AcceptedState::getStateName() const 
{
    return "ACCEPTED";
}

void RejectedState::addCondition(Contract* c, string condition) {
    throw runtime_error("Cannot add condition to contract");
}

void RejectedState::removeCondition(Contract* c, string condition) {
    throw runtime_error("Cannot remove condition from contract");
}

void RejectedState::accept(Contract* c, string party) {
    throw runtime_error("Cannot accept contract");
}

void RejectedState::reject(Contract* c) {
    throw runtime_error("Cannot reject contract");
}

void RejectedState::complete(Contract* c, string party) {
    throw runtime_error("Cannot complete contract");
}

string RejectedState::getStateName() const {
    return "REJECTED";
}

void CompletedState::addCondition(Contract* c, string condition) {
    throw runtime_error("Cannot add condition to contract");
}

void CompletedState::removeCondition(Contract* c, string condition) {
    throw runtime_error("Cannot remove condition from contract");
}

void CompletedState::accept(Contract* c, string party) {
    throw runtime_error("Cannot accept contract");
}

void CompletedState::reject(Contract* c) {
    throw runtime_error("Cannot reject contract");
}

void CompletedState::complete(Contract* c, string party) { 
    throw runtime_error("Cannot complete contract");
}

string CompletedState::getStateName() const {
    return "COMPLETED";
}
