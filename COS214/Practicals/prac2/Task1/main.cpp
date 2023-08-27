#include <iostream>
#include <vector>
#include "Contract.h"
#include "State.h"

int main() {
    // Define the parties involved in the contract
    std::vector<std::string> parties = {"Jeff Bezos", "Andy Jassy"};

    // Create a new contract
    Contract contract("Amazon Worker Exploitation NDA", parties);
    std::cout << "Created a new contract:\n" << contract.toString() << std::endl;

    // Add some conditions
    contract.addCondition("Deny all negotiations for better working conditions");
    contract.addCondition("Deny all negotiations for better pay");
    contract.addCondition("Let workers pee in bottles");
    std::cout << "\nAfter adding conditions:\n" << contract.toString() << std::endl;

    // Remove a condition
    contract.removeCondition("Let workers pee in bottles");
    std::cout << "\nAfter removing a condition:\n" << contract.toString() << std::endl;

    // Accept the contract
    try {
        contract.acceptContract("Jeff Bezos");
        std::cout << "\nAfter Bezos accepts the contract:\n" << contract.toString() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "\nException caught: " << e.what() << std::endl;
    }

    // Reject the contract
    try {
        contract.rejectContract();
        std::cout << "\nAfter rejecting the contract:\n" << contract.toString() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "\nException caught: " << e.what() << std::endl;
    }

    // Complete the contract
    try {
        contract.completeContract("Jeff Bezos");
        std::cout << "\nAfter Bezos completes the contract:\n" << contract.toString() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "\nException caught: " << e.what() << std::endl;
    }

    return 0;
}
