#pragma once
#include <string>

class Calculator {
private:
    std::string inputString;

public:
    std::string getInputString();
    void setInputString(const std::string& inputString);
    void performCalculation();
};
