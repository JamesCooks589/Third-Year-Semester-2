#ifndef ORGSTRUCTURE_H
#define ORGSTRUCTURE_H

#include <vector>
#include <string>

class OrgStructure {
public:
    virtual double getTotalExpenditure() = 0;
    virtual double getExpenditureByCostCenter(const std::string& cost_center) = 0;
};


#endif