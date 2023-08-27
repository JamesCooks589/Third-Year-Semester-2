#include "State.h"
#include "Contract.h"

State::~State() {}


void NegotiationState::addCondition(Contract* c, std::string condition) {
        c->conditions.push_back(condition);
}
void NegotiationState::removeCondition(Contract* c, std::string condition) {
        auto it = std::find(c->conditions.begin(), c->conditions.end(), condition);
        if (it != c->conditions.end()) {
            c->conditions.erase(it);
        }
}
void NegotiationState::acceptContract(Contract* c, std::string party) {
        c->setState(new TentativelyAcceptedState());
        c->votes.push_back(party);
}
void NegotiationState::rejectContract(Contract* c) {
        c->setState(new RejectedState());
}
void NegotiationState::completeContract(Contract* c, std::string party) {
        throw std::runtime_error("Cannot complete contract in current state");
}
std::string NegotiationState::getStateName() const {
    return "NEGOTIATION";
}

void TentativelyAcceptedState::addCondition(Contract* c, std::string condition) {
    c->setState(new NegotiationState());
    c->conditions.push_back(condition);
    c->votes.clear();
}
void TentativelyAcceptedState::removeCondition(Contract* c, std::string condition) {
    auto it = std::find(c->conditions.begin(), c->conditions.end(), condition);
    if (it != c->conditions.end()) {
        c->conditions.erase(it);
    }
    c->votes.clear();
}
void TentativelyAcceptedState::acceptContract(Contract* c, std::string party) {
    if(std::find(c->parties.begin(), c->parties.end(), party) == c->parties.end()) {
        throw std::runtime_error("Party not involved in contract");
    }
    if(c->votes.size() == c->parties.size()) {
        c->setState(new AcceptedState());
    }
}
void TentativelyAcceptedState::rejectContract(Contract* c) {
    throw std::runtime_error("Cannot reject contract in current state");
}
void TentativelyAcceptedState::completeContract(Contract* c, std::string party) {
    throw std::runtime_error("Cannot complete contract in current state");
}
std::string TentativelyAcceptedState::getStateName() const {
    return "TENTATIVELY_ACCEPTED";
}

void AcceptedState::addCondition(Contract* c, std::string condition) {
    throw std::runtime_error("Cannot add condition to contract in current state");
}
void AcceptedState::removeCondition(Contract* c, std::string condition) {
    throw std::runtime_error("Cannot remove condition from contract in current state");
}
void AcceptedState::acceptContract(Contract* c, std::string party) {
    throw std::runtime_error("Cannot accept contract in current state");
}
void AcceptedState::rejectContract(Contract* c) {
    throw std::runtime_error("Cannot reject contract in current state");
}
void AcceptedState::completeContract(Contract* c, std::string party) {
    if(std::find(c->parties.begin(), c->parties.end(), party) == c->parties.end()) {
        throw std::runtime_error("Party not involved in contract");
    }
    if(c->votes.size() == c->parties.size()) {
        c->setState(new CompletedState());
    }
}
std::string AcceptedState::getStateName() const {
    return "ACCEPTED";
}

void RejectedState::addCondition(Contract* c, std::string condition) {
    throw std::runtime_error("Cannot add condition to contract in current state");
}
void RejectedState::removeCondition(Contract* c, std::string condition) {
    throw std::runtime_error("Cannot remove condition from contract in current state");
}
void RejectedState::acceptContract(Contract* c, std::string party) {
    throw std::runtime_error("Cannot accept contract in current state");
}
void RejectedState::rejectContract(Contract* c) {
    throw std::runtime_error("Cannot reject contract in current state");
}
void RejectedState::completeContract(Contract* c, std::string party) {
    throw std::runtime_error("Cannot complete contract in current state");
}
std::string RejectedState::getStateName() const {
    return "REJECTED";
}

void CompletedState::addCondition(Contract* c, std::string condition) {
    throw std::runtime_error("Cannot add condition to contract in current state");
}
void CompletedState::removeCondition(Contract* c, std::string condition) {
    throw std::runtime_error("Cannot remove condition from contract in current state");
}
void CompletedState::acceptContract(Contract* c, std::string party) {
    throw std::runtime_error("Cannot accept contract in current state");
}
void CompletedState::rejectContract(Contract* c) {
    throw std::runtime_error("Cannot reject contract in current state");
}
void CompletedState::completeContract(Contract* c, std::string party) { 
    throw std::runtime_error("Cannot complete contract in current state");
}
std::string CompletedState::getStateName() const {
    return "COMPLETED";
}
