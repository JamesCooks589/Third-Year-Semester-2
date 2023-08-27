#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "OrgStructure.h"

class Individual : public OrgStructure {
private:
    std::string unique_id;
    std::string cost_center;
    double cost_to_company;

public:
    Individual(const std::string& id, const std::string& center, double cost);
    double getTotalExpenditure() override;
    double getExpenditureByCostCenter(const std::string& center) override;
};

#endif
