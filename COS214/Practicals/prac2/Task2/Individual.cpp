#include "Individual.h"

Individual::Individual(const std::string& id, const std::string& center, double cost)
        : unique_id(id), cost_center(center), cost_to_company(cost) {}

double Individual::getTotalExpenditure() {
    return cost_to_company;
}

double Individual::getExpenditureByCostCenter(const std::string& center) {
    if (center == cost_center) {
        return cost_to_company;
    }
    return 0.0;
}
