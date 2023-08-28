#pragma once
#include <string>


using namespace std;

class calculator
{
private:
    string inputString;
public:
    string getInputString();
    void setInputString(string& inputString);
    virtual bool performCalc() = 0;

};
