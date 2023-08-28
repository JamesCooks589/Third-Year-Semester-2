#include <iostream>
#include <string>
#include "NumericCalculator.h"
#include "BooleanCalculator.h"
#include "beforeAndAfter.h"
#include "Testable.h"
#include "NumericTest.h"
#include "BooleanTest.h"

using namespace std;
int main()
{

    cout << "Numeric Calculator Test" << endl;

    calculator* numericCalc = new numericCalculator();

    string numCalculation = "1 + 1 2";
    numericCalc->setInputString(numCalculation);

    test* numTest = new numericTest();

    testBed* testbed = new testBed();
    testbed->setTest(numTest);

    beforeAndAfter testDec;
    testDec.setInternalTestBed(testbed);
    testDec.runTest(*numericCalc);

    delete numericCalc;
    delete numTest;
    delete testbed;

    cout << endl << "Boolean Calculator Test" << endl;

    calculator* booleanCalc = new booleanCalculator();

    string boolCalculation = "T AND T";
    booleanCalc->setInputString(boolCalculation);

    test* boolTest = new booleanTest();
    
    testbed = new testBed();
    testbed->setTest(boolTest);

    testDec.setInternalTestBed(testbed);
    testDec.runTest(*booleanCalc);

    delete booleanCalc;
    delete boolTest;
    delete testbed;




    return 0;
}