#include "beforeAndAfter.h"
#include <iostream>

using namespace std;
void beforeAndAfter::before() const
{
    cout << "|-BEFORE-|" << endl;
}

void beforeAndAfter::after() const
{
    cout << "|-AFTER-|" << endl;
}