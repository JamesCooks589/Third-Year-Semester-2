#ifndef COMPOSITEORGSTRUCTURE_H
#define COMPOSITEORGSTRUCTURE_H

#include "OrgStructure.h"

class CompositeOrgStructure : public OrgStructure {
private:
    std::vector<OrgStructure*> children;

public:
    void add(OrgStructure* org);
    double getTotalExpenditure() override;
    double getExpenditureByCostCenter(const std::string& center) override;
};

#endif