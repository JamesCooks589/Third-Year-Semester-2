#ifndef CONTRACT_H
#define CONTRACT_H

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include "State.h"

class Contract {
public:
    Contract(std::string name, const std::vector<std::string>& parties);
    ~Contract();
    void addCondition(std::string condition);
    void removeCondition(std::string condition);
    void acceptContract(std::string party);
    void rejectContract();
    void completeContract(std::string party);
    std::string toString() const;
    void setState(State* state);
    std::vector<std::string> conditions;
    std::string name;
    State* state;
    std::vector<std::string> parties;
    std::vector<std::string> votes;
};

#endif