#include "Contract.h"
#include "State.h"

Contract::Contract(std::string name, const std::vector<std::string>& parties) : name(name), parties(parties){state = new NegotiationState();}

Contract::~Contract() {
    delete state;
}

void Contract::addCondition(std::string condition) {
    state->addCondition(this, condition);
}

void Contract::removeCondition(std::string condition) {
    state->removeCondition(this, condition);
}

void Contract::acceptContract(std::string party) {
    state->acceptContract(this, party);
}

void Contract::rejectContract() {
    state->rejectContract(this);
}

void Contract::completeContract(std::string party) {
    state->completeContract(this, party);
}

std::string Contract::toString() const {
    std::string result = "Contract " + name + ":\n";
    result += "State: " + state->getStateName() + "\n";

    if (state->getStateName() == "TENTATIVELY_ACCEPTED" || state->getStateName() == "ACCEPTED") {
        result += "Votes:\n";
        for (const auto& vote : votes) {
            result += vote + "\n";
        }
    }

    result += "Conditions:\n";
    for (const auto& condition : conditions) {
        result += condition + "\n";
    }

    return result;
}

void Contract::setState(State* state_) {
   delete state;
   state = state_;
}