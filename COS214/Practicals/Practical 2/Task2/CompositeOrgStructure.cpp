#include "CompositeOrgStructure.h"

void CompositeOrgStructure::add(OrgStructure* org) {
    children.push_back(org);
}

double CompositeOrgStructure::getTotalExpenditure() {
    double total = 0.0;
    for (OrgStructure* child : children) {
        total += child->getTotalExpenditure();
    }
    return total;
}

double CompositeOrgStructure::getExpenditureByCostCenter(const std::string& center) {
    double total = 0.0;
    for (OrgStructure* child : children) {
        total += child->getExpenditureByCostCenter(center);
    }
    return total;
}
