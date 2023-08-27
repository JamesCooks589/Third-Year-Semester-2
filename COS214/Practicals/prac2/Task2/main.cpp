#include "Individual.h"
#include "CompositeOrgStructure.h"
#include <iostream>

int main() {
    // Create some individuals
    Individual john("1", "Marketing", 5000.0);
    Individual jane("2", "Marketing", 6000.0);
    Individual bob("3", "IT", 7000.0);
    Individual alice("4", "IT", 8000.0);

    // Create marketing department and add individuals to it
    CompositeOrgStructure marketing;
    marketing.add(&john);
    marketing.add(&jane);

    // Create IT department and add individuals to it
    CompositeOrgStructure it;
    it.add(&bob);
    it.add(&alice);

    // Create organization and add departments to it
    CompositeOrgStructure organization;
    organization.add(&marketing);
    organization.add(&it);

    // Calculate total expenditure
    std::cout << "Total Expenditure: " << organization.getTotalExpenditure() << std::endl;

    // Calculate expenditure by cost center
    std::cout << "Expenditure for Marketing: " << organization.getExpenditureByCostCenter("Marketing") << std::endl;
    std::cout << "Expenditure for IT: " << organization.getExpenditureByCostCenter("IT") << std::endl;

    return 0;
}
// Total Expenditure: 26000
// Expenditure for Marketing: 11000
// Expenditure for IT: 15000
