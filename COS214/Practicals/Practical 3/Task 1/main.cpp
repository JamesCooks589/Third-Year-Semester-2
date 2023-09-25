#include <iostream>
#include <vector>
#include "contract.h"
#include "states.h"
#include "members.h"

using namespace std;

int main() 
{
    //create parties
    vector<string> parties = {"Manager", "Employee"};

    Members manager("Manager");
    Members employee("Employee");

    
    //create contract
    Contract contract("Work Agreement", parties);
    cout << "Contract:\n" << contract.toString() << endl;
    contract.attach(&manager);
    contract.attach(&employee);

    //slapping some conditions in
    contract.addCondition("Complete all assigned tasks");
    contract.addCondition("Attend all meetings");
    contract.addCondition("Maintain professional conduct");
    cout << "\nAfter adding conditions:\n" << contract.toString() << endl;

    contract.notify();

    // //remove a condition
    // contract.removeCondition("Maintain professional conduct");
    // cout << "\nAfter removing a condition:\n" << contract.toString() << endl;

    // //accept the contract
    // try 
    // {
    //     contract.accept("Manager");
    //     cout << "\nAfter Manager accepts the contract:\n" << contract.toString() << endl;
    // } 
    // catch (const runtime_error& e) 
    // {
    //     cout << "\nException caught: " << e.what() << endl;
    // }

    // //reject the contract
    // try 
    // {
    //     contract.reject();
    //     cout << "\nAfter rejecting the contract:\n" << contract.toString() << endl;
    // } 
    // catch (const runtime_error& e) 
    // {
    //     cout << "\nException caught: " << e.what() << endl;
    // }

    // //complete the contract
    // try 
    // {
    //     contract.complete("Manager");
    //     cout << "\nAfter Manager completes the contract:\n" << contract.toString() << endl;
    // } 
    // catch (const runtime_error& e) 
    // {
    //    cout << "\nException caught: " << e.what() << endl;
    // }
        return 0;
}
